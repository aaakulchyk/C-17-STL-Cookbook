#ifndef C__17_STL_COOKBOOK_STRINGS_TRIM_WHITESPACE_H_
#define C__17_STL_COOKBOOK_STRINGS_TRIM_WHITESPACE_H_

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

std::string trim_whitespace_surrounding(const std::string& s) {
  const char whitespace[] { " \t\n" };
  const size_t first(s.find_first_not_of(whitespace));
  if (std::string::npos == first) {
    return {};
  }
  const size_t last(s.find_last_not_of(whitespace));
  return s.substr(first, last - first + 1);
}

void trim_whitespace() {
  std::string s { " \t\n string surrounded by ugly whitespace\n\t \n "};
  std::cout << "{" << s << "}\n";
  std::cout << "{" << trim_whitespace_surrounding(s) << "}\n";
}

#endif // C__17_STL_COOKBOOK_STRINGS_TRIM_WHITESPACE_H_
