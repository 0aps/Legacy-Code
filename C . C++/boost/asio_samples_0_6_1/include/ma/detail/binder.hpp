//
// Copyright (c) 2010-2013 Marat Abrarov (abrarov@mail.ru)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MA_DETAIL_BINDER_HPP
#define MA_DETAIL_BINDER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <cstddef>
#include <ma/config.hpp>
#include <ma/handler_alloc_helpers.hpp>
#include <ma/handler_invoke_helpers.hpp>
#include <ma/handler_cont_helpers.hpp>

#if defined(MA_HAS_RVALUE_REFS)
#include <utility>
#include <ma/type_traits.hpp>
#endif // defined(MA_HAS_RVALUE_REFS)

namespace ma {
namespace detail {

/// Provides binders with support of Asio specificity.
/**
 * Functors created by listed binders forward Asio allocation/execution
 * strategies to the ones provided by source handler.
 *
 * "Alloctaion strategy" means handler related pair of free functions:
 * asio_handler_allocate and asio_handler_deallocate or the default ones
 * defined by Asio.
 * http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/reference/Handler.html
 *
 * "Execution strategy" means handler related free function asio_handler_invoke
 * or the default one defined by Asio.
 * http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/reference/Handler.html
 *
 * The source handler must meet the requirements of Asio handler.
 * The binded arguments must meet the requirements of Asio handler except
 * existance of asio_handler_allocate, asio_handler_deallocate,
 * asio_handler_invoke and operator() - these functions aren't applied to
 * binded arguments.
 * The functors created by means of listed binders meet the requirements of
 * Asio handler.
 *
 * Usage of free functions called ma::bind_handler can help in construction of
 * functors.
 *
 * It's a modified copy of Boost.Asio sources: asio/detail/bind_handler.hpp.
 * The reason of copy is that those sources are in private area of Boost.Asio.
 *
 * Move semantic supported.
 * Move constructor is explicitly defined to support MSVC 2010/2012.
 */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4512)
#endif // #if defined(_MSC_VER)

template <typename Handler, typename Arg1>
class binder1
{
private:
  typedef binder1<Handler, Arg1> this_type;

public:
  typedef void result_type;

#if defined(MA_HAS_RVALUE_REFS)

  template <typename H, typename A1>
  binder1(H&& handler, A1&& arg1)
    : handler_(std::forward<H>(handler))
    , arg1_(std::forward<A1>(arg1))
  {
  }

#if defined(MA_NO_IMPLICIT_MOVE_CONSTRUCTOR) || !defined(NDEBUG)

  binder1(this_type&& other)
    : handler_(std::move(other.handler_))
    , arg1_(std::move(other.arg1_))
  {
  }

  binder1(const this_type& other)
    : handler_(other.handler_)
    , arg1_(other.arg1_)
  {
  }

#endif

#else // defined(MA_HAS_RVALUE_REFS)

  binder1(const Handler& handler, const Arg1& arg1)
    : handler_(handler)
    , arg1_(arg1)
  {
  }

#endif // defined(MA_HAS_RVALUE_REFS)

#if !defined(NDEBUG)
  ~binder1()
  {
  }
#endif

  void operator()()
  {
    handler_(static_cast<const Arg1&>(arg1_));
  }

  void operator()() const
  {
    handler_(arg1_);
  }

  friend void* asio_handler_allocate(std::size_t size, this_type* context)
  {
    // Forward to asio_handler_allocate provided by source handler.
    return ma_handler_alloc_helpers::allocate(size, context->handler_);
  }

  friend void asio_handler_deallocate(void* pointer, std::size_t size,
      this_type* context)
  {
    // Forward to asio_handler_deallocate provided by source handler.
    ma_handler_alloc_helpers::deallocate(pointer, size, context->handler_);
  }

#if defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(Function&& function, this_type* context)
  {
    // Forward to asio_handler_invoke provided by source handler.
    ma_handler_invoke_helpers::invoke(
        std::forward<Function>(function), context->handler_);
  }

#else // defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(const Function& function, this_type* context)
  {
    // Forward to asio_handler_invoke provided by source handler.
    ma_handler_invoke_helpers::invoke(function, context->handler_);
  }

#endif // defined(MA_HAS_RVALUE_REFS)

  friend bool asio_handler_is_continuation(this_type* context)
  {
    return ma_handler_cont_helpers::is_continuation(context->handler_);
  }

private:
  Handler handler_;
  Arg1 arg1_;
}; // class binder1

#if defined(_MSC_VER)
#pragma warning(pop)
#endif // #if defined(_MSC_VER)

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4512)
#endif // #if defined(_MSC_VER)

template <typename Handler, typename Arg1, typename Arg2>
class binder2
{
private:
  typedef binder2<Handler, Arg1, Arg2> this_type;

public:
  typedef void result_type;

#if defined(MA_HAS_RVALUE_REFS)

  template <typename H, typename A1, typename A2>
  binder2(H&& handler, A1&& arg1, A2&& arg2)
    : handler_(std::forward<H>(handler))
    , arg1_(std::forward<A1>(arg1))
    , arg2_(std::forward<A2>(arg2))
  {
  }

#if defined(MA_NO_IMPLICIT_MOVE_CONSTRUCTOR) || !defined(NDEBUG)

  binder2(this_type&& other)
    : handler_(std::move(other.handler_))
    , arg1_(std::move(other.arg1_))
    , arg2_(std::move(other.arg2_))
  {
  }

  binder2(const this_type& other)
    : handler_(other.handler_)
    , arg1_(other.arg1_)
    , arg2_(other.arg2_)
  {
  }

#endif

#else // defined(MA_HAS_RVALUE_REFS)

  binder2(const Handler& handler, const Arg1& arg1, const Arg2& arg2)
    : handler_(handler)
    , arg1_(arg1)
    , arg2_(arg2)
  {
  }

#endif // defined(MA_HAS_RVALUE_REFS)

#if !defined(NDEBUG)
  ~binder2()
  {
  }
#endif

  void operator()()
  {
    handler_(static_cast<const Arg1&>(arg1_), static_cast<const Arg2&>(arg2_));
  }

  void operator()() const
  {
    handler_(arg1_, arg2_);
  }

  friend void* asio_handler_allocate(std::size_t size, this_type* context)
  {
    return ma_handler_alloc_helpers::allocate(size, context->handler_);
  }

  friend void asio_handler_deallocate(void* pointer, std::size_t size,
      this_type* context)
  {
    ma_handler_alloc_helpers::deallocate(pointer, size, context->handler_);
  }

#if defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(Function&& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(
        std::forward<Function>(function), context->handler_);
  }

#else // defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(const Function& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(function, context->handler_);
  }

#endif // defined(MA_HAS_RVALUE_REFS)

  friend bool asio_handler_is_continuation(this_type* context)
  {
    return ma_handler_cont_helpers::is_continuation(context->handler_);
  }

private:
  Handler handler_;
  Arg1 arg1_;
  Arg2 arg2_;
}; // class binder2

#if defined(_MSC_VER)
#pragma warning(pop)
#endif // #if defined(_MSC_VER)

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4512)
#endif // #if defined(_MSC_VER)

template <typename Handler, typename Arg1, typename Arg2, typename Arg3>
class binder3
{
private:
  typedef binder3<Handler, Arg1, Arg2, Arg3> this_type;

public:
  typedef void result_type;

#if defined(MA_HAS_RVALUE_REFS)

  template <typename H, typename A1, typename A2, typename A3>
  binder3(H&& handler, A1&& arg1, A2&& arg2, A3&& arg3)
    : handler_(std::forward<H>(handler))
    , arg1_(std::forward<A1>(arg1))
    , arg2_(std::forward<A2>(arg2))
    , arg3_(std::forward<A3>(arg3))
  {
  }

#if defined(MA_NO_IMPLICIT_MOVE_CONSTRUCTOR) || !defined(NDEBUG)

  binder3(this_type&& other)
    : handler_(std::move(other.handler_))
    , arg1_(std::move(other.arg1_))
    , arg2_(std::move(other.arg2_))
    , arg3_(std::move(other.arg3_))
  {
  }

  binder3(const this_type& other)
    : handler_(other.handler_)
    , arg1_(other.arg1_)
    , arg2_(other.arg2_)
    , arg3_(other.arg3_)
  {
  }

#endif

#else // defined(MA_HAS_RVALUE_REFS)

  binder3(const Handler& handler, const Arg1& arg1, const Arg2& arg2,
      const Arg3& arg3)
    : handler_(handler)
    , arg1_(arg1)
    , arg2_(arg2)
    , arg3_(arg3)
  {
  }

#endif // defined(MA_HAS_RVALUE_REFS)

#if !defined(NDEBUG)
  ~binder3()
  {
  }
#endif

  void operator()()
  {
    handler_(static_cast<const Arg1&>(arg1_), static_cast<const Arg2&>(arg2_),
        static_cast<const Arg3&>(arg3_));
  }

  void operator()() const
  {
    handler_(arg1_, arg2_, arg3_);
  }

  friend void* asio_handler_allocate(std::size_t size, this_type* context)
  {
    return ma_handler_alloc_helpers::allocate(size, context->handler_);
  }

  friend void asio_handler_deallocate(void* pointer, std::size_t size,
      this_type* context)
  {
    ma_handler_alloc_helpers::deallocate(pointer, size, context->handler_);
  }

#if defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(Function&& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(
        std::forward<Function>(function), context->handler_);
  }

#else // defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(const Function& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(function, context->handler_);
  }

#endif // defined(MA_HAS_RVALUE_REFS)

  friend bool asio_handler_is_continuation(this_type* context)
  {
    return ma_handler_cont_helpers::is_continuation(context->handler_);
  }

private:
  Handler handler_;
  Arg1 arg1_;
  Arg2 arg2_;
  Arg3 arg3_;
}; // class binder3

#if defined(_MSC_VER)
#pragma warning(pop)
#endif // #if defined(_MSC_VER)

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4512)
#endif // #if defined(_MSC_VER)

template <typename Handler, typename Arg1, typename Arg2, typename Arg3,
    typename Arg4>
class binder4
{
private:
  typedef binder4<Handler, Arg1, Arg2, Arg3, Arg4> this_type;

public:
  typedef void result_type;

#if defined(MA_HAS_RVALUE_REFS)

  template <typename H, typename A1, typename A2, typename A3, typename A4>
  binder4(H&& handler, A1&& arg1, A2&& arg2, A3&& arg3, A4&& arg4)
    : handler_(std::forward<H>(handler))
    , arg1_(std::forward<A1>(arg1))
    , arg2_(std::forward<A2>(arg2))
    , arg3_(std::forward<A3>(arg3))
    , arg4_(std::forward<A4>(arg4))
  {
  }

#if defined(MA_NO_IMPLICIT_MOVE_CONSTRUCTOR) || !defined(NDEBUG)

  binder4(this_type&& other)
    : handler_(std::move(other.handler_))
    , arg1_(std::move(other.arg1_))
    , arg2_(std::move(other.arg2_))
    , arg3_(std::move(other.arg3_))
    , arg4_(std::move(other.arg4_))
  {
  }

  binder4(const this_type& other)
    : handler_(other.handler_)
    , arg1_(other.arg1_)
    , arg2_(other.arg2_)
    , arg3_(other.arg3_)
    , arg4_(other.arg4_)
  {
  }

#endif

#else // defined(MA_HAS_RVALUE_REFS)

  binder4(const Handler& handler, const Arg1& arg1, const Arg2& arg2,
      const Arg3& arg3, const Arg4& arg4)
    : handler_(handler)
    , arg1_(arg1)
    , arg2_(arg2)
    , arg3_(arg3)
    , arg4_(arg4)
  {
  }

#endif // defined(MA_HAS_RVALUE_REFS)

#if !defined(NDEBUG)
  ~binder4()
  {
  }
#endif

  void operator()()
  {
    handler_(static_cast<const Arg1&>(arg1_), static_cast<const Arg2&>(arg2_),
        static_cast<const Arg3&>(arg3_), static_cast<const Arg4&>(arg4_));
  }

  void operator()() const
  {
    handler_(arg1_, arg2_, arg3_, arg4_);
  }

  friend void* asio_handler_allocate(std::size_t size, this_type* context)
  {
    return ma_handler_alloc_helpers::allocate(size, context->handler_);
  }

  friend void asio_handler_deallocate(void* pointer, std::size_t size,
      this_type* context)
  {
    ma_handler_alloc_helpers::deallocate(pointer, size, context->handler_);
  }

#if defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(Function&& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(
        std::forward<Function>(function), context->handler_);
  }

#else //defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(const Function& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(function, context->handler_);
  }

#endif // defined(MA_HAS_RVALUE_REFS)

  friend bool asio_handler_is_continuation(this_type* context)
  {
    return ma_handler_cont_helpers::is_continuation(context->handler_);
  }

private:
  Handler handler_;
  Arg1 arg1_;
  Arg2 arg2_;
  Arg3 arg3_;
  Arg4 arg4_;
}; // class binder4

#if defined(_MSC_VER)
#pragma warning(pop)
#endif // #if defined(_MSC_VER)

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4512)
#endif // #if defined(_MSC_VER)

template <typename Handler, typename Arg1, typename Arg2, typename Arg3,
    typename Arg4, typename Arg5>
class binder5
{
private:
  typedef binder5<Handler, Arg1, Arg2, Arg3, Arg4, Arg5> this_type;

public:
  typedef void result_type;

#if defined(MA_HAS_RVALUE_REFS)

  template <typename H, typename A1, typename A2, typename A3, typename A4,
      typename A5>
  binder5(H&& handler, A1&& arg1, A2&& arg2, A3&& arg3, A4&& arg4, A5&& arg5)
    : handler_(std::forward<H>(handler))
    , arg1_(std::forward<A1>(arg1))
    , arg2_(std::forward<A2>(arg2))
    , arg3_(std::forward<A3>(arg3))
    , arg4_(std::forward<A4>(arg4))
    , arg5_(std::forward<A5>(arg5))
  {
  }

#if defined(MA_NO_IMPLICIT_MOVE_CONSTRUCTOR) || !defined(NDEBUG)

  binder5(this_type&& other)
    : handler_(std::move(other.handler_))
    , arg1_(std::move(other.arg1_))
    , arg2_(std::move(other.arg2_))
    , arg3_(std::move(other.arg3_))
    , arg4_(std::move(other.arg4_))
    , arg5_(std::move(other.arg5_))
  {
  }

  binder5(const this_type& other)
    : handler_(other.handler_)
    , arg1_(other.arg1_)
    , arg2_(other.arg2_)
    , arg3_(other.arg3_)
    , arg4_(other.arg4_)
    , arg5_(other.arg5_)
  {
  }

#endif

#else // defined(MA_HAS_RVALUE_REFS)

  binder5(const Handler& handler, const Arg1& arg1, const Arg2& arg2,
      const Arg3& arg3, const Arg4& arg4, const Arg5& arg5)
    : handler_(handler)
    , arg1_(arg1)
    , arg2_(arg2)
    , arg3_(arg3)
    , arg4_(arg4)
    , arg5_(arg5)
  {
  }

#endif // defined(MA_HAS_RVALUE_REFS)

#if !defined(NDEBUG)
  ~binder5()
  {
  }
#endif

  void operator()()
  {
    handler_(static_cast<const Arg1&>(arg1_), static_cast<const Arg2&>(arg2_),
        static_cast<const Arg3&>(arg3_), static_cast<const Arg4&>(arg4_),
        static_cast<const Arg5&>(arg5_));
  }

  void operator()() const
  {
    handler_(arg1_, arg2_, arg3_, arg4_, arg5_);
  }

  friend void* asio_handler_allocate(std::size_t size, this_type* context)
  {
    return ma_handler_alloc_helpers::allocate(size, context->handler_);
  }

  friend void asio_handler_deallocate(void* pointer, std::size_t size,
      this_type* context)
  {
    ma_handler_alloc_helpers::deallocate(pointer, size, context->handler_);
  }

#if defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(Function&& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(
        std::forward<Function>(function), context->handler_);
  }

#else // defined(MA_HAS_RVALUE_REFS)

  template <typename Function>
  friend void asio_handler_invoke(const Function& function, this_type* context)
  {
    ma_handler_invoke_helpers::invoke(function, context->handler_);
  }

#endif // defined(MA_HAS_RVALUE_REFS)

  friend bool asio_handler_is_continuation(this_type* context)
  {
    return ma_handler_cont_helpers::is_continuation(context->handler_);
  }

private:
  Handler handler_;
  Arg1 arg1_;
  Arg2 arg2_;
  Arg3 arg3_;
  Arg4 arg4_;
  Arg5 arg5_;
}; // class binder5

#if defined(_MSC_VER)
#pragma warning(pop)
#endif // #if defined(_MSC_VER)

} // namespace detail
} // namespace ma

#endif // MA_DETAIL_BINDER_HPP
