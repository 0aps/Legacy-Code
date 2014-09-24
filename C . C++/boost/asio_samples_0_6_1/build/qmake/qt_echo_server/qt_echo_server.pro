#
# Copyright (c) 2010-2013 Marat Abrarov (abrarov@mail.ru)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#

TEMPLATE  = app
QT       += core gui
TARGET    = qt_echo_server
CONFIG   += qt thread

# Qt 5 support
greaterThan(QT_MAJOR_VERSION, 4) {
  QT     += widgets
}

# Common project configuration
include(../config.pri)

HEADERS  += ../../../include/ma/echo/server/qt/custommetatypes.h \
            ../../../include/ma/echo/server/qt/execution_config.h \
            ../../../include/ma/echo/server/qt/execution_config_fwd.h \
            ../../../include/ma/echo/server/qt/serviceforwardsignal_fwd.h \
            ../../../include/ma/echo/server/qt/serviceservantsignal_fwd.h \
            ../../../include/ma/echo/server/qt/servicestate.h \
            ../../../include/ma/echo/server/qt/service_fwd.h \
            ../../../include/ma/echo/server/qt/meta_type_register_error.h \
            ../../../include/ma/echo/server/qt/signal_connect_error.h \
            ../../../include/ma/echo/server/qt/service.h \
            ../../../include/ma/echo/server/qt/serviceforwardsignal.h \
            ../../../include/ma/echo/server/qt/serviceservantsignal.h \
            ../../../include/ma/echo/server/qt/mainform.h \
            ../../../include/ma/echo/server/session_config_fwd.hpp \
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
            ../../../include/ma/bind_handler.hpp \
            ../../../include/ma/config.hpp \
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

SOURCES  += ../../../src/ma/echo/server/qt/custommetatypes.cpp \
            ../../../src/ma/echo/server/qt/service.cpp \
            ../../../src/ma/echo/server/qt/mainform.cpp \
            ../../../src/ma/echo/server/error.cpp \
            ../../../src/ma/echo/server/session.cpp \
            ../../../src/ma/echo/server/session_manager.cpp \
            ../../../src/ma/echo/server/pooled_session_factory.cpp \
            ../../../src/ma/echo/server/simple_session_factory.cpp \
            ../../../src/qt_echo_server/main.cpp

FORMS    += ../../../src/ma/echo/server/qt/mainform.ui

RC_FILE   = ../../../src/qt_echo_server/qt_echo_server.rc

INCLUDEPATH += $${BOOST_INCLUDE} \
               ../../../include

LIBS       += -L$${BOOST_LIB}
win32:LIBS += -lkernel32 \
              -luser32 \
              -lgdi32 \
              -lshell32 \
              -lcomdlg32 \
              -luuid \
              -lole32 \
              -loleaut32 \
              -ladvapi32 \
              -lws2_32 \
              -limm32 \
              -lwinmm \
              -lwinspool
unix:LIBS  += $${BOOST_LIB}/libboost_system.a \
              $${BOOST_LIB}/libboost_thread.a \
              $${BOOST_LIB}/libboost_date_time.a
exists($${BOOST_INCLUDE}/boost/chrono.hpp) {
  unix:LIBS += $${BOOST_LIB}/libboost_chrono.a \
               -lrt
}

win32:DEFINES += WINVER=0x0500 \
                 _WIN32_WINNT=0x0500
