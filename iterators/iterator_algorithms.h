#ifndef C__17_STL_COOKBOOK_ITERATORS_ITERATOR_ALGORITHMS_H_
#define C__17_STL_COOKBOOK_ITERATORS_ITERATOR_ALGORITHMS_H_

#include <algorithm>
#include <iostream>
#include <iterator>

class fibit {
 public:
  fibit() = default;

  explicit fibit(size_t i)
  : i_ { i } {}

  // Emit a Fibonacci number on dereferencing
  size_t operator*() const {
    return b_;
  }

  // Compute the next Fibonacci number when incrementing
  fibit& operator++() {
    const size_t oldB { b_ };
    b_ += a_;
    a_ = oldB;
    ++i_;
    return *this;
  }

  // Needed to use in loop
  bool operator!=(const fibit &o) const {
    return i_ != o.i_;
  }

 private:
  size_t i_ { 0 };
  size_t a_ { 0 };
  size_t b_ { 1 };
}; // class fibit

class fib_range {
 public:
  explicit fib_range(size_t endN)
  : endN_ { endN } {}

  // Define `begin` and `end` member functions to allow for range-based for-loop
  [[nodiscard]] fibit begin() const {
    return fibit {};
  }

  [[nodiscard]] fibit end() const {
    return fibit { endN_ };
  }

 private:
  size_t endN_;
}; // class fib_range

namespace std {

template <>
struct iterator_traits<fibit> {
  using iterator_category = std::forward_iterator_tag;
  using value_type = size_t;
}; // struct iterator_traits<fibit>

} // namespace std

void iterator_algorithms() {
  fib_range fibGen { 10 };
  std::copy(std::begin(fibGen), std::end(fibGen), std::ostream_iterator<size_t> { std::cout, ", " });
  std::cout << std::endl;
}

#endif // C__17_STL_COOKBOOK_ITERATORS_ITERATOR_ALGORITHMS_H_
