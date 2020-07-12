#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_COPYING_ITEMS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_COPYING_ITEMS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <tuple>
#include <vector>

namespace std { // NOLINT

ostream& operator<<(ostream& os, const pair<int, string>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

} // namespace std

void copying_items() {
  std::vector<std::pair<int, std::string>> v {
      { 1, "one" },
      { 2, "two" },
      { 3, "three" },
      { 4, "four" },
      { 5, "five" },
  };

  std::map<int, std::string> m;

  // Copy exactly three pairs
  std::copy_n(std::begin(v), 3, std::inserter(m, std::begin(m)));

  auto shell_it(std::ostream_iterator<std::pair<int, std::string>> { std::cout, ", " });
  std::copy(std::begin(m), std::end(m), shell_it);
  std::cout << '\n';

  // Use std::move and see what happens
  m.clear();
  std::move(std::begin(v), std::end(v), std::inserter(m, std::begin(m)));
  std::copy(std::begin(m), std::end(m), shell_it);
  std::cout << '\n';
  std::copy(std::begin(v), std::end(v), shell_it);
  std::cout << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_COPYING_ITEMS_H_
