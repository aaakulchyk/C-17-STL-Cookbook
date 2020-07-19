#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_REMOVING_CONSECUTIVE_WHITESPACE_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_REMOVING_CONSECUTIVE_WHITESPACE_H_

#include <algorithm>
#include <iostream>
#include <string>

template <typename It>
It remove_multi_whitespace(It it, It end_it) {
  return std::unique(it, end_it, [](const auto& a, const auto& b) {
    return std::isspace(a) && std::isspace(b);
  });
}

void removing_consecutive_whitespace() {
  std::string s { "fooo   bar  \t baz" };
  std::cout << s << '\n';

  s.erase(remove_multi_whitespace(std::begin(s), std::end(s)), std::end(s));
  std::cout << s << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_REMOVING_CONSECUTIVE_WHITESPACE_H_
