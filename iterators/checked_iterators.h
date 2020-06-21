#ifndef C__17_STL_COOKBOOK_ITERATORS_CHECKED_ITERATORS_H_
#define C__17_STL_COOKBOOK_ITERATORS_CHECKED_ITERATORS_H_

// Set this G++ flag to run sanitizer and debug
#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>

void checked_iterators() {
  std::vector v { 1, 2, 3 };
  v.shrink_to_fit();
  const auto it(std::begin(v));

  // Print the dereferenced iterator
  std::cout << *it << '\n';

  // Cause memory reallocation
  v.push_back(123);

  // Unsafe code: `it` may point to freed location
  std::cout << *it << '\n';
}

#endif // C__17_STL_COOKBOOK_ITERATORS_CHECKED_ITERATORS_H_
