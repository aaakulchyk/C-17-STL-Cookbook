#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_COMPRESSING_DECOMPRESSING_STRINGS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_COMPRESSING_DECOMPRESSING_STRINGS_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

template <typename It>
std::tuple<It, char, size_t> occurrences(It it, It end_it) {
  if (it == end_it) {
    return { it, '?', 0 };
  }
  const char c { *it };
  const auto diff(std::find_if(it, end_it, [c](char x) { return c != x; }));
  return { diff, c, std::distance(it, diff) };
}

std::string compress(const std::string& s) {
  const auto end_it { std::end(s) };
  std::stringstream ss;
  for (auto it { std::begin(s) }; it != end_it;) {
    const auto [next_diff, c, n](occurrences(it, end_it));
    ss << c << n;
    it = next_diff;
  }
  return ss.str();
}

std::string decompress(const std::string& s) {
  std::stringstream ss { s };
  std::stringstream r;
  char c;
  size_t n;
  while (ss >> c >> n) {
    r << std::string(n, c);
  }
  return r.str();
}

void compressing_decompressing_strings() {
  std::string s { "aaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccc" };
  std::cout << compress(s) << '\n' << decompress(compress(s)) << std::endl;
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_COMPRESSING_DECOMPRESSING_STRINGS_H_
