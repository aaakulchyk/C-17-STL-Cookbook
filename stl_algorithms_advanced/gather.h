#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_GATHER_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_GATHER_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

template <typename It, typename F>
std::pair<It, It> _gather(It first, It last, It gather_pos, F predicate) {
  return {
    std::stable_partition(first, gather_pos, std::not_fn(predicate)),
    std::stable_partition(gather_pos, last, predicate)
  };
}

template <typename It, typename F>
void gather_sort(It first, It last, It gather_pos, F comp_func) {
  auto inv_comp_func([&](const auto&... ps) {
    return !comp_func(ps...);
  });
  std::stable_sort(first, gather_pos, inv_comp_func);
  std::stable_sort(gather_pos, last, comp_func);
}

void gather() {
  auto is_a([](char c) {
    return c == 'a';
  });
  std::string a { "a_a_a_a_a_a_a_a_a_a_a_a_a_a_a_a" };
  auto middle(std::begin(a) + a.size() / 2);

  _gather(std::begin(a), std::end(a), middle, is_a);
  std::cout << a << '\n';

  _gather(std::begin(a), std::end(a), std::begin(a), is_a);
  std::cout << a << '\n';

  _gather(std::begin(a), std::end(a), std::end(a), is_a);
  std::cout << a << '\n';

  _gather(std::begin(a), std::end(a), middle, is_a);
  std::cout << a << '\n';

  std::string b { "_9_2_4_7_3_8_1_6_5_0_" };
  gather_sort(std::begin(b), std::end(b), std::begin(b) + b.size() / 2, std::less<char> {});
  std::cout << b << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_GATHER_H_
