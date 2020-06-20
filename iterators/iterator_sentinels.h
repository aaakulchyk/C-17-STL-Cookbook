#ifndef C__17_STL_COOKBOOK_ITERATORS_ITERATOR_SENTINELS_H_
#define C__17_STL_COOKBOOK_ITERATORS_ITERATOR_SENTINELS_H_

#include <iostream>

// Define iterator sentinel
class CStringIteratorSentinel {};

// Implement iterator
class CStringIterator {
 public:
  explicit CStringIterator(const char* str)
  : s_ { str } {}

  // When dereferencing iterator, return char value
  char operator*() const {
    return *s_;
  }

  // When incrementing, just move the position of iterator
  CStringIterator& operator++() {
    ++s_;
    return *this;
  }

  // Implement comparison operator for comparing an iterator with an iterator sentinel
  bool operator!=(const CStringIteratorSentinel) const {
    return s_ != nullptr && *s_ != '\0';
  }

 private:
  const char* s_ { nullptr };

}; // class CStringIterator

// Implement range class to allow for range-based for-loop
class CStringRange {
 public:
  explicit CStringRange(const char* str)
  : s_ { str } {}

  [[nodiscard]] CStringIterator begin() const {
    return CStringIterator { s_ };
  }

  [[nodiscard]] CStringIteratorSentinel end() const { // NOLINT
    return {};
  }

 private:
  const char* s_ { nullptr };

}; // class CStringRange

int iterator_sentinels(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Please provide one parameter\n";
    return 1;
  }

  for (auto c : CStringRange(argv[1]))
    std::cout << c;
  std::cout << '\n';
  return 0;
}

#endif // C__17_STL_COOKBOOK_ITERATORS_ITERATOR_SENTINELS_H_
