#ifndef C__17_STL_COOKBOOK_ITERATORS_ITERABLE_RANGE_H_
#define C__17_STL_COOKBOOK_ITERATORS_ITERABLE_RANGE_H_

#include <iostream>

class NumIterator {
 public:
  // Mark constructor as `explicit` to avoid undesired implicit type conversions
  explicit NumIterator(int position = 0)
  : i_ { position } {}

  // Return an integer when dereferencing
  int operator*() const {
    return i_;
  }

  // Increment integer when moving forward
  NumIterator& operator++() {
    ++i_;
    return *this;
  }

  bool operator!=(const NumIterator& other) const {
    return i_ != other.i_;
  }

 private:
  int i_;
}; // class NumIterator

class NumRange {
 public:
  NumRange(int from, int to)
  : a_ { from },
    b_ { to } {}

  // To use range-based for-loop we must implement `begin` and `end` funcs
  [[nodiscard]] NumIterator begin() const {
    return NumIterator { a_ };
  }

  [[nodiscard]] NumIterator end() const {
    return NumIterator { b_ };
  }

 private:
  int a_;
  int b_;
}; // class NumRange

void iterable_range() {
 for (auto i : NumRange { 69, 420 + 1 })
   std::cout << i << ' ';
 std::cout << std::endl;
}

#endif // C__17_STL_COOKBOOK_ITERATORS_ITERABLE_RANGE_H_
