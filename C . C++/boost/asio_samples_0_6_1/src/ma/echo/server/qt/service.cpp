/*
TRANSLATOR ma::echo::server::qt::Service
*/

//
// Copyright (c) 2010-2013 Marat Abrarov (abrarov@mail.ru)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <vector>
#include <boost/ref.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/assert.hpp>
#include <boost/make_shared.hpp>
#include <boost/noncopyable.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/thread/thread.hpp>
#include <ma/echo/server/error.hpp>
#include <ma/echo/server/simple_session_factory.hpp>
#include <ma/echo/server/pooled_session_factory.hpp>
#include <ma/echo/server/session_manager.hpp>
#include <ma/echo/server/qt/execution_config.h>
#include <ma/echo/server/qt/signal_connect_error.h>
#include <ma/echo/server/qt/serviceforwardsignal.h>
#include <ma/echo/server/qt/serviceservantsignal.h>
#include <ma/echo/server/qt/service.h>

namespace ma {
namespace echo {
namespace server {
namespace qt {

namespace {

typedef boost::shared_ptr<boost::asio::io_service> io_service_ptr;
typedef std::vector<io_service_ptr>                io_service_vector;
typedef boost::shared_ptr<ma::echo::server::session_factory>
    session_factory_ptr;
typedef boost::shared_ptr<boost::asio::io_service::work> io_service_work_ptr;
typedef std::vector<io_service_work_ptr> io_service_work_vector;

class server_base_0 : private boost::noncopyable
{
public:
  explicit server_base_0(const execution_config& config)
    : ios_per_work_thread_(config.ios_per_work_thread)
    , session_manager_thread_count_(config.session_manager_thread_count)
    , session_thread_count_(config.session_thread_count)
    , session_io_services_(create_session_io_services(config))
  {
  }

  io_service_vector session_io_services() const
  {
    return session_io_services_;
  }

protected:
  ~server_base_0()
  {
  }

  const bool ios_per_work_thread_;
  const std::size_t session_manager_thread_count_;
  const std::size_t session_thread_count_;
  const io_service_vector session_io_services_;

private:
  static io_service_vector create_session_io_services(
      const execution_config& exec_config)
  {
    io_service_vector io_services;
    if (exec_config.ios_per_work_thread)
    {
      for (std::size_t i = 0; i != exec_config.session_thread_count; ++i)
      {
        io_services.push_back(boost::make_shared<boost::asio::io_service>(1));
      }
    }
    else
    {
      io_service_ptr io_service = boost::make_shared<boost::asio::io_service>(
          exec_config.session_thread_count);
      io_services.push_back(io_service);
    }
    return io_services;
  }
}; // class server_base_0

class server_base_1 : public server_base_0
{
public:
  server_base_1(const execution_config& exec_config,
      const ma::echo::server::session_manager_config& session_manager_config)
    : server_base_0(exec_config)
    , session_factory_(create_session_factory(exec_config,
          session_manager_config, session_io_services_))
  {
  }

  ma::echo::server::session_factory& session_factory() const
  {
    return *session_factory_;
  }

protected:
  ~server_base_1()
  {
  }

  const session_factory_ptr session_factory_;

private:
  static session_factory_ptr create_session_factory(
      const execution_config& exec_config,
      const ma::echo::server::session_manager_config& session_manager_config,
      const io_service_vector& session_io_services)
  {
    if (exec_config.ios_per_work_thread)
    {
      return boost::make_shared<ma::echo::server::pooled_session_factory>(
          session_io_services, session_manager_config.recycled_session_count);
    }
    else
    {
      boost::asio::io_service& io_service = *session_io_services.front();
      return boost::make_shared<ma::echo::server::simple_session_factory>(
          boost::ref(io_service),
          session_manager_config.recycled_session_count);
    }
  }
}; // class server_base_1

class server_base_2 : public server_base_1
{
public:
  explicit server_base_2(const execution_config& exec_config,
      const ma::echo::server::session_manager_config& session_manager_config)
    : server_base_1(exec_config, session_manager_config)
    , session_manager_io_service_(exec_config.session_manager_thread_count)
  {
  }

  boost::asio::io_service& session_manager_io_service()
  {
    return session_manager_io_service_;
  }

protected:
  ~server_base_2()
  {
  }

  boost::asio::io_service session_manager_io_service_;
}; // class server_base_2

class server_base_3 : public server_base_2
{
private:
  typedef server_base_3 this_type;

public:
  template <typename Handler>
  server_base_3(const execution_config& exec_config,
      const ma::echo::server::session_manager_config& session_manager_config,
      const Handler& exception_handler)
    : server_base_2(exec_config, session_manager_config)
    , session_work_(create_works(session_io_services_))
    , session_manager_work_(session_manager_io_service_)
    , threads_()
  {
    create_threads(exception_handler);
  }

  ~server_base_3()
  {
    stop_threads();
  }

private:
  template <typename Handler>
  void create_threads(const Handler& handler)
  {
    typedef boost::tuple<Handler> wrapped_handler_type;
    typedef void (*thread_func_type)(boost::asio::io_service&,
        wrapped_handler_type);

    wrapped_handler_type wrapped_handler = boost::make_tuple(handler);
    thread_func_type func = &this_type::thread_func<Handler>;

    if (ios_per_work_thread_)
    {
      for (io_service_vector::const_iterator i = session_io_services_.begin(),
          end = session_io_services_.end(); i != end; ++i)
      {
        threads_.create_thread(
            boost::bind(func, boost::ref(**i), wrapped_handler));
      }
    }
    else
    {
      boost::asio::io_service& io_service = *session_io_services_.front();
      for (std::size_t i = 0; i != session_thread_count_; ++i)
      {
        threads_.create_thread(
            boost::bind(func, boost::ref(io_service), wrapped_handler));
      }
    }

    for (std::size_t i = 0; i != session_manager_thread_count_; ++i)
    {
      threads_.create_thread(boost::bind(func,
          boost::ref(session_manager_io_service_), wrapped_handler));
    }
  }

  void stop_threads()
  {
    session_manager_io_service_.stop();
    stop(session_io_services_);
    threads_.join_all();
  }

  template <typename Handler>
  static void thread_func(boost::asio::io_service& io_service,
      boost::tuple<Handler> handler)
  {
    try
    {
      io_service.run();
    }
    catch (...)
    {
      boost::get<0>(handler)();
    }
  }

  static io_service_work_vector create_works(
      const io_service_vector& io_services)
  {
    io_service_work_vector works;
    for (io_service_vector::const_iterator i = io_services.begin(),
        end = io_services.end(); i != end; ++i)
    {
      works.push_back(
          boost::make_shared<boost::asio::io_service::work>(boost::ref(**i)));
    }
    return works;
  }

  static void stop(const io_service_vector& io_services)
  {
    for (io_service_vector::const_iterator i = io_services.begin(),
        end = io_services.end(); i != end; ++i)
    {
      (*i)->stop();
    }
  }

  const io_service_work_vector session_work_;
  const boost::asio::io_service::work session_manager_work_;
  boost::thread_group threads_;
}; // class server_base_3

} // anonymous namespace

class Service::server : public server_base_3
{
private:
  typedef server this_type;

public:
  template <typename Handler>
  server(const execution_config& the_execution_config,
      const session_manager_config& the_session_manager_config,
      const Handler& exception_handler)
    : server_base_3(the_execution_config, the_session_manager_config,
          exception_handler)
    , session_manager_(session_manager::create(session_manager_io_service_,
          *session_factory_, the_session_manager_config))
  {
  }

  ~server()
  {
  }

  template <typename Handler>
  void async_start(const Handler& handler)
  {
    session_manager_->async_start(handler);
  }

  template <typename Handler>
  void async_wait(const Handler& handler)
  {
    session_manager_->async_wait(handler);
  }

  template <typename Handler>
  void async_stop(const Handler& handler)
  {
    session_manager_->async_stop(handler);
  }

  session_manager_stats stats() const
  {
    return session_manager_->stats();
  }

private:
  session_manager_ptr session_manager_;
}; // class Service::server

Service::Service(QObject* parent)
  : QObject(parent)
  , state_(ServiceState::Stopped)
  , stats_()
  , server_()
  , servantSignal_()
{
  forwardSignal_ = new ServiceForwardSignal(this);

  checkConnect(QObject::connect(forwardSignal_,
      SIGNAL(startCompleted(const boost::system::error_code&)),
      SIGNAL(startCompleted(const boost::system::error_code&)),
      Qt::QueuedConnection));

  checkConnect(QObject::connect(forwardSignal_,
      SIGNAL(stopCompleted(const boost::system::error_code&)),
      SIGNAL(stopCompleted(const boost::system::error_code&)),
      Qt::QueuedConnection));

  checkConnect(QObject::connect(forwardSignal_,
      SIGNAL(workCompleted(const boost::system::error_code&)),
      SIGNAL(workCompleted(const boost::system::error_code&)),
      Qt::QueuedConnection));
}

Service::~Service()
{
}

session_manager_stats Service::stats() const
{
  if (server_)
  {
    return server_->stats();
  }
  else
  {
    return stats_;
  }
}

void Service::asyncStart(const execution_config& the_execution_config,
    const session_manager_config& the_session_manager_config)
{
  if (ServiceState::Stopped != state_)
  {
    forwardSignal_->emitStartCompleted(echo::server::error::invalid_state);
    return;
  }

  createServant(the_execution_config, the_session_manager_config);
  server_->async_start(boost::bind(&ServiceServantSignal::emitStartCompleted,
      servantSignal_, _1));
  state_ = ServiceState::Starting;
}

void Service::onServantStartCompleted(const boost::system::error_code& error)
{
  if (ServiceState::Starting != state_)
  {
    return;
  }

  if (error)
  {
    destroyServant();
    state_ = ServiceState::Stopped;
  }
  else
  {
    server_->async_wait(boost::bind(&ServiceServantSignal::emitWaitCompleted,
        servantSignal_, _1));
    state_ = ServiceState::Working;
  }

  emit startCompleted(error);
}

void Service::asyncStop()
{
  if ((ServiceState::Stopped == state_) || (ServiceState::Stopping == state_))
  {
    forwardSignal_->emitStopCompleted(echo::server::error::invalid_state);
    return;
  }

  switch (state_)
  {
  case ServiceState::Starting:
    forwardSignal_->emitStartCompleted(echo::server::error::operation_aborted);
    break;

  case ServiceState::Working:
    forwardSignal_->emitWorkCompleted(echo::server::error::operation_aborted);
    break;

  default:
    BOOST_ASSERT_MSG(false, "unsupported ServiceState");
    break;
  }

  server_->async_stop(boost::bind(&ServiceServantSignal::emitStopCompleted,
      servantSignal_, _1));
  state_ = ServiceState::Stopping;
}

void Service::onServantStopCompleted(const boost::system::error_code& error)
{
  if (ServiceState::Stopping != state_)
  {
    return;
  }

  destroyServant();
  state_ = ServiceState::Stopped;
  emit stopCompleted(error);
}

void Service::terminate()
{
  destroyServant();

  switch (state_)
  {
  case ServiceState::Starting:
    forwardSignal_->emitStartCompleted(echo::server::error::operation_aborted);
    break;

  case ServiceState::Working:
    forwardSignal_->emitWorkCompleted(echo::server::error::operation_aborted);
    break;

  case ServiceState::Stopping:
    forwardSignal_->emitStopCompleted(echo::server::error::operation_aborted);
    break;

  case ServiceState::Stopped:
    // Do nothing
    break;

  default:
    BOOST_ASSERT_MSG(false, "unsupported ServiceState");
    break;
  }

  state_ = ServiceState::Stopped;
}

void Service::onServantWaitCompleted(const boost::system::error_code& error)
{
  if (ServiceState::Working == state_)
  {
    emit workCompleted(error);
  }
}

void Service::onServantWorkThreadExceptionHappened()
{
  if (ServiceState::Stopped != state_)
  {
    emit exceptionHappened();
  }
}

void Service::createServant(const execution_config& the_execution_config,
    const session_manager_config& the_session_manager_config)
{
  servantSignal_ = boost::make_shared<ServiceServantSignal>();

  checkConnect(QObject::connect(servantSignal_.get(),
      SIGNAL(workThreadExceptionHappened()),
      SLOT(onServantWorkThreadExceptionHappened()),
      Qt::QueuedConnection));

  checkConnect(QObject::connect(servantSignal_.get(),
      SIGNAL(startCompleted(const boost::system::error_code&)),
      SLOT(onServantStartCompleted(const boost::system::error_code&)),
      Qt::QueuedConnection));

  checkConnect(QObject::connect(servantSignal_.get(),
      SIGNAL(waitCompleted(const boost::system::error_code&)),
      SLOT(onServantWaitCompleted(const boost::system::error_code&)),
      Qt::QueuedConnection));

  checkConnect(QObject::connect(servantSignal_.get(),
      SIGNAL(stopCompleted(const boost::system::error_code&)),
      SLOT(onServantStopCompleted(const boost::system::error_code&)),
      Qt::QueuedConnection));

  server_.reset(new server(
      the_execution_config, the_session_manager_config,
      boost::bind(&ServiceServantSignal::emitWorkThreadExceptionHappened,
          servantSignal_)));

  stats_ = server_->stats();
}

void Service::destroyServant()
{
  if (servantSignal_)
  {
    servantSignal_->disconnect();
    servantSignal_.reset();
  }
  stats_ = server_->stats();
  server_.reset();
}

} // namespace qt
} // namespace server
} // namespace echo
} // namespace ma
