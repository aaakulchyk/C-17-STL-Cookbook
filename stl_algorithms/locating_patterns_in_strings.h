#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_LOCATING_PATTERNS_IN_STRINGS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_LOCATING_PATTERNS_IN_STRINGS_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

template <typename It>
static void print(It it, size_t chars) {
  std::copy_n(it, chars, std::ostream_iterator<char> { std::cout });
  std::cout << '\n';
}

void locating_patterns_in_strings() {
  const std::string long_string {
    "Lorem ipsum dolor sit amet, consetetur"
    " sadipscing elitr, sed diam nonumy eirmod"
  };
  const std::string needle { "elitr" };

  // The old interface of `std::search` accepts two range iterators of the source and two range iterators of the target
  // strings
  {
    auto match { std::search(std::begin(long_string), std::end(long_string),
         std::begin(needle), std::end(needle)) };
    print(match, needle.size());
  }

  // C++17 interface of `std::search` accepts two range iterators of the source string and a searcher object.
  // The searcher object is by default `std::default_searcher`, which accepts two range iterators of the target string.
  {
    auto match { std::search(std::begin(long_string), std::end(long_string),
        std::default_searcher(std::begin(needle), std::end(needle))) };
    print(match, needle.size());
  }

  // The point of this is to have the ability to switch between different searching algorithms
  {
    auto match { std::search(std::begin(long_string), std::end(long_string),
        std::boyer_moore_searcher(std::begin(needle), std::end(needle))) };
    print(match, needle.size());
  }

  {
    auto match { std::search(std::begin(long_string), std::end(long_string),
        std::boyer_moore_horspool_searcher(std::begin(needle), std::end(needle))) };
    print(match, needle.size());
  }
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_LOCATING_PATTERNS_IN_STRINGS_H_
