/*
 * circular_buffer.h
 *
 *  Created on: Oct 24, 2016
 *      Author: 224474
 */

#ifndef INCLUDE_CIRCULAR_BUFFER_H_
#define INCLUDE_CIRCULAR_BUFFER_H_

#include <vector>

template <class T>
class CircularBuffer {
  public:
    explicit CircularBuffer(
        size_t capacity = 100)
        : array_(new T[capacity]),
          array_size_(capacity),
          head_(0), tail_(0),
          contents_size_(0) {}
    
    ~CircularBuffer()
        { delete [] array_; }
    
    typedef T          value_type;
    typedef T         *pointer;
    typedef const T   *const_pointer;
    typedef T         &reference;
    typedef const T   &const_reference;
    typedef size_t     size_type;
    typedef ptrdiff_t  difference_type;
    
    reference front() { return array_[head_]; }
    reference back() { return array_[tail_]; }
    const_reference front() const { return array_[head_]; }
    const_reference back() const { return array_[tail_]; }    
    
    void clear() { head_ = tail_ = contents_size_ = 0; }
    
    void push_back(const value_type &item) {
      if (!contents_size_) {
        array_[head_] = item;
        tail_ = head_;
        ++contents_size_;
      }
      else if (contents_size_ != array_size_)
      {
        increment_tail();
        array_[tail_] = item;
      }
      else {
        // We always accept data when full
        // and lose the front()
        increment_head();
        increment_tail();
        array_[tail_] = item;
      }
    }
    
    void pop_front() { increment_head(); }
    
    size_type size() const {return contents_size_;}
    size_type capacity() const {return array_size_;}
    bool empty() const { return 0 == contents_size_;}
    size_type max_size() const { return size_type(-1) / sizeof(value_type);}
    
  private:
    T      *array_;
    size_t  array_size_;
    size_t  head_;
    size_t  tail_;
    size_t  contents_size_;
    void increment_tail() {
      ++tail_;
      ++contents_size_;
      if (tail_ == array_size_) tail_ = 0;
    }
    
    void increment_head(){
      // precondition: !empty()
      ++head_;
      --contents_size_;
      if (head_ == array_size_) head_ = 0;
    }
};



#endif /* INCLUDE_CIRCULAR_BUFFER_H_ */
