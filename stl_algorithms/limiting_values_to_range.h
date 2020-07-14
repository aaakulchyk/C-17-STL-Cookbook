#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_LIMITING_VALUES_TO_RANGE_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_LIMITING_VALUES_TO_RANGE_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// Build a normalizing functional object
static auto norm(int min, int max, int new_max) {
  const double diff(max - min);
  // Project values from the old range to a smaller range that we want to have
  return [=](int val) {
    return static_cast<int>((val - min) / diff * new_max);
  };
}

// Build a functional object that captures the min and max values and calls std::clamp
static auto clampval(int min, int max) {
  // Limit values in a vector to this new range by min and max thresholds
  return [=](int val) -> int {
    return std::clamp(val, min, max);
  };
}

void limiting_values_to_range() {
  std::vector v { 0, 1000, 5, 250, 300, 800, 900, 321 };
  const auto [min_it, max_it] { std::minmax_element(std::begin(v), std::end(v)) };

  // Copy all the values from the first vector to a new one
  std::vector<int> v_norm;
  v_norm.reserve(v.size());
  std::transform(std::begin(v), std::end(v), std::back_inserter(v_norm),
      norm(*min_it, *max_it, 255));
  std::cout << "Values after calling `norm`:\n";
  std::copy(std::begin(v_norm), std::end(v_norm), std::ostream_iterator<int> { std::cout, ", " });
  std::cout << '\n';

  std::transform(std::begin(v), std::end(v), std::begin(v_norm), clampval(0, 255));
  std::cout << "Values after calling `clampval`:\n";
  std::copy(std::begin(v_norm), std::end(v_norm), std::ostream_iterator<int> { std::cout, ", " });
  std::cout << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_LIMITING_VALUES_TO_RANGE_H_
