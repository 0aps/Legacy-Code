//
// Copyright (c) 2010-2013 Marat Abrarov (abrarov@mail.ru)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#if defined(WIN32)
#include <tchar.h>
#endif

#include <cstdlib>
#include <iostream>
#include <exception>
#include <boost/ref.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/format.hpp>
#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/make_shared.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <ma/handler_allocator.hpp>
#include <ma/console_close_guard.hpp>
#include <ma/tutorial2/async_interface.hpp>
#include <ma/tutorial2/async_implementation.hpp>
#include <ma/tutorial2/do_something_handler.hpp>

namespace {

class do_something_handler_implementation
  : public ma::tutorial2::do_something_handler
  , private boost::noncopyable
{
public:
  do_something_handler_implementation(
      const ma::tutorial2::async_interface_ptr& async_interface,
      const std::string& name)
    : async_interface_(async_interface)
    , name_(name)
    , allocator_()
  {
  }

  ~do_something_handler_implementation()
  {
  }

  virtual void handle_do_something_completion(
      const boost::system::error_code& error)
  {
    if (error)
    {
      std::cout << boost::format("%s complete work with error\n") % name_;
    }
    else
    {
      std::cout << boost::format("%s successfully complete work\n") % name_;
    }
  }

  virtual void* allocate(std::size_t size)
  {
    return allocator_.allocate(size);
  }

  virtual void deallocate(void* pointer)
  {
    allocator_.deallocate(pointer);
  }

private:
  // For example only: handler "holds up" active object itself
  ma::tutorial2::async_interface_ptr async_interface_;
  std::string name_;
  ma::in_place_handler_allocator<128> allocator_;
}; // class do_something_handler_implementation

void handle_program_exit(boost::asio::io_service& io_service)
{
  std::cout << "User exit request detected. Stopping work io_service...\n";
  io_service.stop();
  std::cout << "Work io_service stopped.\n";
}

} // anonymous namespace

#if defined(WIN32)
int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
#else
int main(int /*argc*/, char* /*argv*/[])
#endif
{
  try
  {
    std::size_t cpu_count = boost::thread::hardware_concurrency();
    std::size_t work_thread_count = cpu_count < 2 ? 2 : cpu_count;

    using boost::asio::io_service;
    io_service work_io_service(cpu_count);

    // Setup console controller
    ma::console_close_guard console_close_guard(
        boost::bind(handle_program_exit, boost::ref(work_io_service)));

    std::cout << "Press Ctrl+C to exit.\n";

    boost::thread_group work_threads;
    boost::optional<io_service::work> work_guard(
        boost::in_place(boost::ref(work_io_service)));
    for (std::size_t i = 0; i != work_thread_count; ++i)
    {
      work_threads.create_thread(boost::bind(
          &io_service::run, boost::ref(work_io_service)));
    }

    boost::format name_format("active_object%03d");
    for (std::size_t i = 0; i != 20; ++i)
    {
      std::string name = (name_format % i).str();

      ma::tutorial2::async_interface_ptr active_object =
          ma::tutorial2::async_implementation::create(work_io_service, name);

      active_object->async_do_something(
          boost::make_shared<do_something_handler_implementation>(
              active_object, name));
    }

    work_guard = boost::none;
    work_threads.join_all();

    return EXIT_SUCCESS;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Unexpected error: " << e.what() << std::endl;
  }
  catch (...)
  {
    std::cerr << "Unknown exception" << std::endl;
  }
  return EXIT_FAILURE;
}
