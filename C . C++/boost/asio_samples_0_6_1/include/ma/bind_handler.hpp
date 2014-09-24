//
// Copyright (c) 2010-2013 Marat Abrarov (abrarov@mail.ru)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MA_BIND_HANDLER_HPP
#define MA_BIND_HANDLER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <cstddef>
#include <ma/config.hpp>
#include <ma/detail/binder.hpp>

#if defined(MA_HAS_RVALUE_REFS)
#include <utility>
#include <ma/type_traits.hpp>
#endif // defined(MA_HAS_RVALUE_REFS)

namespace ma {

#if defined(MA_HAS_RVALUE_REFS)

/// Helper for creation of binded handler.
template <typename Handler, typename Arg1>
inline detail::binder1<typename remove_cv_reference<Handler>::type,
    typename remove_cv_reference<Arg1>::type>
bind_handler(Handler&& handler, Arg1&& arg1)
{
  typedef typename remove_cv_reference<Handler>::type handler_type;
  typedef typename remove_cv_reference<Arg1>::type arg1_type;
  return detail::binder1<handler_type, arg1_type>(
      std::forward<Handler>(handler), std::forward<Arg1>(arg1));
}

template <typename Handler, typename Arg1, typename Arg2>
inline detail::binder2<typename remove_cv_reference<Handler>::type,
    typename remove_cv_reference<Arg1>::type,
    typename remove_cv_reference<Arg2>::type>
bind_handler(Handler&& handler, Arg1&& arg1, Arg2&& arg2)
{
  typedef typename remove_cv_reference<Handler>::type handler_type;
  typedef typename remove_cv_reference<Arg1>::type arg1_type;
  typedef typename remove_cv_reference<Arg2>::type arg2_type;
  return detail::binder2<handler_type, arg1_type, arg2_type>(
      std::forward<Handler>(handler), std::forward<Arg1>(arg1),
      std::forward<Arg2>(arg2));
}

template <typename Handler, typename Arg1, typename Arg2, typename Arg3>
inline detail::binder3<typename remove_cv_reference<Handler>::type,
    typename remove_cv_reference<Arg1>::type,
    typename remove_cv_reference<Arg2>::type,
    typename remove_cv_reference<Arg3>::type>
bind_handler(Handler&& handler, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3)
{
  typedef typename remove_cv_reference<Handler>::type handler_type;
  typedef typename remove_cv_reference<Arg1>::type arg1_type;
  typedef typename remove_cv_reference<Arg2>::type arg2_type;
  typedef typename remove_cv_reference<Arg3>::type arg3_type;
  return detail::binder3<handler_type, arg1_type, arg2_type, arg3_type>(
      std::forward<Handler>(handler), std::forward<Arg1>(arg1),
      std::forward<Arg2>(arg2), std::forward<Arg3>(arg3));
}

template <typename Handler, typename Arg1, typename Arg2, typename Arg3,
    typename Arg4>
inline detail::binder4<typename remove_cv_reference<Handler>::type,
    typename remove_cv_reference<Arg1>::type,
    typename remove_cv_reference<Arg2>::type,
    typename remove_cv_reference<Arg3>::type,
    typename remove_cv_reference<Arg4>::type>
bind_handler(Handler&& handler, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3,
    Arg4&& arg4)
{
  typedef typename remove_cv_reference<Handler>::type handler_type;
  typedef typename remove_cv_reference<Arg1>::type arg1_type;
  typedef typename remove_cv_reference<Arg2>::type arg2_type;
  typedef typename remove_cv_reference<Arg3>::type arg3_type;
  typedef typename remove_cv_reference<Arg4>::type arg4_type;
  return detail::binder4<handler_type, arg1_type, arg2_type, 
      arg3_type, arg4_type>(std::forward<Handler>(handler), 
          std::forward<Arg1>(arg1), std::forward<Arg2>(arg2),
          std::forward<Arg3>(arg3), std::forward<Arg4>(arg4));
}

template <typename Handler, typename Arg1, typename Arg2, typename Arg3,
    typename Arg4, typename Arg5>
inline detail::binder5<typename remove_cv_reference<Handler>::type,
    typename remove_cv_reference<Arg1>::type,
    typename remove_cv_reference<Arg2>::type,
    typename remove_cv_reference<Arg3>::type,
    typename remove_cv_reference<Arg4>::type,
    typename remove_cv_reference<Arg5>::type>
bind_handler(Handler&& handler, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3,
    Arg4&& arg4, Arg5&& arg5)
{
  typedef typename remove_cv_reference<Handler>::type handler_type;
  typedef typename remove_cv_reference<Arg1>::type arg1_type;
  typedef typename remove_cv_reference<Arg2>::type arg2_type;
  typedef typename remove_cv_reference<Arg3>::type arg3_type;
  typedef typename remove_cv_reference<Arg4>::type arg4_type;
  typedef typename remove_cv_reference<Arg5>::type arg5_type;
  return detail::binder5<handler_type, arg1_type, arg2_type, 
      arg3_type, arg4_type, arg5_type>(std::forward<Handler>(handler),
          std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), 
          std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), 
          std::forward<Arg5>(arg5));
}

#else // defined(MA_HAS_RVALUE_REFS)

/// Helper for creation of binded handler.
template <typename Handler, typename Arg1>
inline detail::binder1<Handler, Arg1>
bind_handler(const Handler& handler, const Arg1& arg1)
{
  return detail::binder1<Handler, Arg1>(handler, arg1);
}

template <typename Handler, typename Arg1, typename Arg2>
inline detail::binder2<Handler, Arg1, Arg2>
bind_handler(const Handler& handler, const Arg1& arg1, const Arg2& arg2)
{
  return detail::binder2<Handler, Arg1, Arg2>(handler, arg1, arg2);
}

template <typename Handler, typename Arg1, typename Arg2, typename Arg3>
inline detail::binder3<Handler, Arg1, Arg2, Arg3>
bind_handler(const Handler& handler, const Arg1& arg1, const Arg2& arg2,
    const Arg3& arg3)
{
  return detail::binder3<Handler, Arg1, Arg2, Arg3>(handler, arg1, arg2, arg3);
}

template <typename Handler, typename Arg1, typename Arg2, typename Arg3,
    typename Arg4>
inline detail::binder4<Handler, Arg1, Arg2, Arg3, Arg4>
bind_handler(const Handler& handler, const Arg1& arg1, const Arg2& arg2,
    const Arg3& arg3, const Arg4& arg4)
{
  return detail::binder4<Handler, Arg1, Arg2, Arg3, Arg4>(handler, 
      arg1, arg2, arg3, arg4);
}

template <typename Handler, typename Arg1, typename Arg2, typename Arg3,
    typename Arg4, typename Arg5>
inline detail::binder5<Handler, Arg1, Arg2, Arg3, Arg4, Arg5>
bind_handler(const Handler& handler, const Arg1& arg1, const Arg2& arg2,
    const Arg3& arg3, const Arg4& arg4, const Arg5& arg5)
{
  return detail::binder5<Handler, Arg1, Arg2, Arg3, Arg4, Arg5>(handler, 
      arg1, arg2, arg3, arg4, arg5);
}

#endif // defined(MA_HAS_RVALUE_REFS)

} // namespace ma

#endif // MA_BIND_HANDLER_HPP
