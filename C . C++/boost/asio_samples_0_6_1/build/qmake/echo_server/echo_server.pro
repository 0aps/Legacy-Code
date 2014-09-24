#
# Copyright (c) 2010-2013 Marat Abrarov (abrarov@mail.ru)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

TEMPLATE  = app
QT       -= core gui
TARGET    = echo_server
CONFIG   += console thread
CONFIG   -= app_bundle

# Common project configuration
include(../config.pri)

HEADERS  += ../../../include/ma/echo/server/session_config_fwd.hpp \
            ../../../include/ma/echo/server/session_manager_config_fwd.hpp \
            ../../../include/ma/echo/server/session_manager_stats.hpp \
            ../../../include/ma/echo/server/session_manager_stats_fwd.hpp \
            ../../../include/ma/echo/server/session_config.hpp \
            ../../../include/ma/echo/server/session_manager_config.hpp \
            ../../../include/ma/echo/server/session_fwd.hpp \
            ../../../include/ma/echo/server/session_manager_fwd.hpp \
            ../../../include/ma/echo/server/error.hpp \
            ../../../include/ma/echo/server/session.hpp \
            ../../../include/ma/echo/server/session_manager.hpp \
            ../../../include/ma/echo/server/session_manager_fwd.hpp \
            ../../../include/ma/echo/server/pooled_session_factory.hpp \
            ../../../include/ma/echo/server/session_factory.hpp \
            ../../../include/ma/echo/server/session_factory_fwd.hpp \
            ../../../include/ma/echo/server/simple_session_factory.hpp \
            ../../../include/ma/detail/binder.hpp \
            ../../../include/ma/detail/handler_ptr.hpp \
            ../../../include/ma/detail/intrusive_list.hpp \
            ../../../include/ma/detail/service_base.hpp \
            ../../../include/ma/detail/sp_singleton.hpp \
            ../../../include/ma/windows/console_signal.hpp \
            ../../../include/ma/windows/console_signal_service.hpp \
            ../../../include/ma/bind_handler.hpp \
            ../../../include/ma/config.hpp \
            ../../../include/ma/console_close_guard.hpp \
            ../../../include/ma/context_alloc_handler.hpp \
            ../../../include/ma/context_wrapped_handler.hpp \
            ../../../include/ma/custom_alloc_handler.hpp \
            ../../../include/ma/cyclic_buffer.hpp \
            ../../../include/ma/handler_alloc_helpers.hpp \
            ../../../include/ma/handler_allocator.hpp \
            ../../../include/ma/handler_cont_helpers.hpp \
            ../../../include/ma/handler_invoke_helpers.hpp \
            ../../../include/ma/handler_storage.hpp \
            ../../../include/ma/handler_storage_service.hpp \
            ../../../include/ma/limited_int.hpp \
            ../../../include/ma/shared_ptr_factory.hpp \
            ../../../include/ma/sp_intrusive_list.hpp \
            ../../../include/ma/steady_deadline_timer.hpp \
            ../../../include/ma/strand_wrapped_handler.hpp \
            ../../../include/ma/type_traits.hpp

SOURCES  += ../../../src/ma/echo/server/error.cpp \
            ../../../src/ma/echo/server/session.cpp \
            ../../../src/ma/echo/server/session_manager.cpp \
            ../../../src/ma/echo/server/pooled_session_factory.cpp \
            ../../../src/ma/echo/server/simple_session_factory.cpp \
            ../../../src/ma/windows/console_signal_service.cpp \
            ../../../src/ma/console_close_guard.cpp \
            ../../../src/echo_server/config.cpp \
            ../../../src/echo_server/main.cpp

INCLUDEPATH += $${BOOST_INCLUDE} \
               ../../../include

LIBS       += -L$${BOOST_LIB}
unix:LIBS  += $${BOOST_LIB}/libboost_system.a \
              $${BOOST_LIB}/libboost_thread.a \
              $${BOOST_LIB}/libboost_date_time.a \
              $${BOOST_LIB}/libboost_program_options.a
exists($${BOOST_INCLUDE}/boost/chrono.hpp) {
  unix:LIBS += $${BOOST_LIB}/libboost_chrono.a \
               -lrt
}

win32:DEFINES += WINVER=0x0500 \
                 _WIN32_WINNT=0x0500
