#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_SPLIT_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_SPLIT_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

template <typename InIt, typename OutIt, typename T, typename F>
InIt _split(InIt it, InIt end_it, OutIt out_it, T split_val, F bin_func) {
  while (it != end_it) {
    auto slice_end(std::find(it, end_it, split_val));
    *out_it++ = bin_func(it, slice_end);
    if (slice_end == end_it) {
      return end_it;
    }
    it = std::next(slice_end);
  }
  return it;
}

void split() {
  const std::string s { "a-b-c-d-e-f-g" };
  auto binfunc([](auto it_a, auto it_b) {
    return std::string(it_a, it_b);
  });

  std::list<std::string> l;
  _split(std::begin(s), std::end(s), std::back_inserter(l), '-', binfunc);
  for (const auto& item : l) {
    std::cout << item << '\n';
  }
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_SPLIT_H_
