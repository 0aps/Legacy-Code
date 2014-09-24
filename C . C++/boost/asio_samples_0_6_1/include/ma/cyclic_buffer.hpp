//
// Copyright (c) 2010-2013 Marat Abrarov (abrarov@mail.ru)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MA_CYCLIC_BUFFER_HPP
#define MA_CYCLIC_BUFFER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <cstddef>
#include <utility>
#include <stdexcept>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/throw_exception.hpp>
#include <boost/scoped_array.hpp>

namespace ma {

/// Input/output buffer with circular behaviour.
/**
 * Buffer space is limited and cannot grow up. Also buffer space is separated
 * into the two sequences:
 *
 * @li nonfilled (input) sequence,
 * @li filled (output) sequence.
 *
 * It is not guaranteed each sequence to be represented as one continuous
 * memory block. In general each sequence can be represented by zero, one or
 * two continuous memory blocks - Asio buffers.
 */
class cyclic_buffer : private boost::noncopyable
{
private:

  /// Generalized buffer sequence that represents cyclic_buffer sequence:
  /// nonfilled or filled.
  /**
   * buffers_2 is CopyConstructible to meet Asio constant/mutable buffer
   * sequence requirements. See:
   * http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/reference/ConstBufferSequence.html
   * and
   * http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/reference/MutableBufferSequence.html
   */
  template <typename Buffer>
  class buffers_2
  {
  public:
    /// Asio requirements.
    typedef Buffer            value_type;
    typedef const value_type* const_iterator;

    buffers_2();
    explicit buffers_2(const value_type& buffer1);
    buffers_2(const value_type& buffer1, const value_type& buffer2);

    /// Asio requirement.
    const_iterator begin() const;

    /// Asio requirement.
    const_iterator end() const;

    /// Small but useful optimization.
    bool empty() const;

  private:
    boost::array<value_type, 2> buffers_;
    std::size_t buffers_count_;
  }; // class buffers_2

public:
  /// Constant buffer sequence.
  typedef buffers_2<boost::asio::const_buffer>   const_buffers_type;
  /// Mutable buffer sequence.
  typedef buffers_2<boost::asio::mutable_buffer> mutable_buffers_type;

  explicit cyclic_buffer(std::size_t size);

  /// Return buffer to the state as was right after construction.
  void reset();

  /// Reduce filled sequence by marking first size bytes of filled sequence as
  /// nonfilled sequence.
  /**
   * Doesn't move or copy anything. Size of nonfilled sequence grows up by size
   * bytes. Start of nonfilled sequence doesn't change. Size of filled sequence
   * reduces by size bytes. Start of filled sequence moves up (circular) by
   * size bytes.
   */
  void commit(std::size_t size);

  /// Reduce nonfilled sequence by marking first size bytes of
  /// nonfilled sequence as filled sequence.
  /**
   * Doesn't move or copy anything. Size of filled sequence grows up by size
   * bytes. Start of filled sequence doesn't change. Size of nonfilled sequence
   * reduces by size bytes. Start of nonfilled sequence moves up (circular) by
   * size bytes.
   */
  void consume(std::size_t size);

  /// Return constant buffer sequence representing filled sequence.
  const_buffers_type data() const;

  /// Return mutable buffer sequence representing nonfilled sequence.
  mutable_buffers_type prepared() const;

  /// Return constant buffer sequence representing filled sequence.
  /// The size of returned buffer sequence is not greater than max_size.
  const_buffers_type data(std::size_t max_size) const;

  /// Return mutable buffer sequence representing nonfilled sequence.
  /// The size of returned buffer sequence is not greater than max_size.
  mutable_buffers_type prepared(std::size_t max_size) const;

private:
  boost::scoped_array<char> data_;
  std::size_t size_;
  std::size_t nonfilled_start_;
  std::size_t nonfilled_size_;
  std::size_t filled_start_;
  std::size_t filled_size_;
}; // class cyclic_buffer

template <typename Buffer>
cyclic_buffer::buffers_2<Buffer>::buffers_2()
  : buffers_count_(0)
{
}

template <typename Buffer>
cyclic_buffer::buffers_2<Buffer>::buffers_2(const value_type& buffer1)
  : buffers_count_(1)
{
  buffers_[0] = buffer1;
}

template <typename Buffer>
cyclic_buffer::buffers_2<Buffer>::buffers_2(
    const value_type& buffer1, const value_type& buffer2)
  : buffers_count_(2)
{
  buffers_[0] = buffer1;
  buffers_[1] = buffer2;
}

template <typename Buffer>
typename cyclic_buffer::buffers_2<Buffer>::const_iterator
cyclic_buffer::buffers_2<Buffer>::begin() const
{
  return boost::addressof(buffers_[0]);
}

template <typename Buffer>
typename cyclic_buffer::buffers_2<Buffer>::const_iterator
cyclic_buffer::buffers_2<Buffer>::end() const
{
  return boost::addressof(buffers_[0]) + buffers_count_;
}

template <typename Buffer>
bool cyclic_buffer::buffers_2<Buffer>::empty() const
{
  return !buffers_count_;
}

inline cyclic_buffer::cyclic_buffer(std::size_t size)
  : data_(new char[size])
  , size_(size)
  , nonfilled_start_(0)
  , nonfilled_size_(size)
  , filled_start_(0)
  , filled_size_(0)
{
}

inline void cyclic_buffer::reset()
{
  nonfilled_size_  = size_;
  nonfilled_start_ = filled_start_ = filled_size_ = 0;
}

inline void cyclic_buffer::commit(std::size_t size)
{
  if (size > filled_size_)
  {
    boost::throw_exception(std::length_error(
        "filled sequence size is too small to consume given size"));
  }
  filled_size_    -= size;
  nonfilled_size_ += size;
  std::size_t d = size_ - filled_start_;
  if (size < d)
  {
    filled_start_ += size;
  }
  else
  {
    filled_start_ = size - d;
  }
}

inline void cyclic_buffer::consume(std::size_t size)
{
  if (size > nonfilled_size_)
  {
    boost::throw_exception(std::length_error(
        "nonfilled sequence size is too small to consume given size"));
  }
  filled_size_    += size;
  nonfilled_size_ -= size;
  std::size_t d = size_ - nonfilled_start_;
  if (size < d)
  {
    nonfilled_start_ += size;
  }
  else
  {
    nonfilled_start_ = size - d;
  }
}

inline cyclic_buffer::const_buffers_type cyclic_buffer::data() const
{
  if (!filled_size_)
  {
    return const_buffers_type();
  }
  std::size_t d = size_ - filled_start_;
  if (filled_size_ > d)
  {
    return const_buffers_type(
        boost::asio::const_buffer(data_.get() + filled_start_, d),
        boost::asio::const_buffer(data_.get(), filled_size_ - d));
  }
  return const_buffers_type(boost::asio::const_buffer(
      data_.get() + filled_start_, filled_size_));
}

inline cyclic_buffer::mutable_buffers_type cyclic_buffer::prepared() const
{
  if (!nonfilled_size_)
  {
    return mutable_buffers_type();
  }
  std::size_t d = size_ - nonfilled_start_;
  if (nonfilled_size_ > d)
  {
    return mutable_buffers_type(
        boost::asio::mutable_buffer(data_.get() + nonfilled_start_, d),
        boost::asio::mutable_buffer(data_.get(), nonfilled_size_ - d));
  }
  return mutable_buffers_type(boost::asio::mutable_buffer(
      data_.get() + nonfilled_start_, nonfilled_size_));
}

inline cyclic_buffer::const_buffers_type
cyclic_buffer::data(std::size_t max_size) const
{
  if (!filled_size_)
  {
    return const_buffers_type();
  }
  std::size_t buffers_size = (std::min<std::size_t>)(filled_size_, max_size);
  std::size_t d = size_ - filled_start_;
  if (buffers_size > d)
  {
    return const_buffers_type(
        boost::asio::const_buffer(data_.get() + filled_start_, d),
        boost::asio::const_buffer(data_.get(), buffers_size - d));
  }
  return const_buffers_type(boost::asio::const_buffer(
      data_.get() + filled_start_, buffers_size));
}

inline cyclic_buffer::mutable_buffers_type
cyclic_buffer::prepared(std::size_t max_size) const
{
  if (!nonfilled_size_)
  {
    return mutable_buffers_type();
  }
  std::size_t buffers_size =
      (std::min<std::size_t>)(nonfilled_size_, max_size);
  std::size_t d = size_ - nonfilled_start_;
  if (buffers_size > d)
  {
    return mutable_buffers_type(
        boost::asio::mutable_buffer(data_.get() + nonfilled_start_, d),
        boost::asio::mutable_buffer(data_.get(), buffers_size - d));
  }
  return mutable_buffers_type(boost::asio::mutable_buffer(
      data_.get() + nonfilled_start_, buffers_size));
}

} // namespace ma

#endif // MA_CYCLIC_BUFFER_HPP
