#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_DICTIONARY_MERGING_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_DICTIONARY_MERGING_H_

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>

using dict_entry = std::pair<std::string, std::string>;

namespace std { // NOLINT

std::ostream& operator<<(std::ostream& os, const dict_entry& p) {
  return os << p.first << " " << p.second;
}

std::istream& operator>>(std::istream& is, dict_entry& p) {
  return is >> p.first >> p.second;
}

} // namespace std

template <typename IS>
std::deque<dict_entry> from_istream(IS&& is) {
  std::deque<dict_entry> d { std::istream_iterator<dict_entry> { is }, {} };
  std::sort(std::begin(d), std::end(d));
  return d;
}

void dictionary_merging() {
  const auto dict1 { from_istream(std::ifstream { "dict.txt" }) };
  const auto dict2 { from_istream(std::cin) };

  // Merge two dictionaries
  std::merge(std::begin(dict1), std::end(dict1), std::begin(dict2), std::end(dict2),
      std::ostream_iterator<dict_entry> { std::cout, "\n" });
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_DICTIONARY_MERGING_H_
