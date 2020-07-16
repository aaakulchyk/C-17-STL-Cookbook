#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_VECTOR_ERROR_SUM_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_VECTOR_ERROR_SUM_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void vector_error_sum() {
  constexpr size_t sig_len { 100 };
  std::vector<double> as(sig_len); // a for analog
  std::vector<int> ds(sig_len); // d for digital

  auto sin_gen([n { 0 }]() mutable {
    return 5.0 * std::sin(n++ * 2.0 * M_PI / 100);
  });

  std::generate(std::begin(as), std::end(as), sin_gen);
  std::copy(std::begin(as), std::end(as), std::begin(ds));

  std::copy(std::begin(as), std::end(as), std::ostream_iterator<double> { std::cout, " " });
  std::cout << '\n';

  std::cout << std::inner_product(std::begin(as), std::end(as), std::begin(ds), 0.0,
      std::plus<double>{},
      [](const double a, const double b) {
      return std::pow(a - b, 2);
  }) << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_VECTOR_ERROR_SUM_H_
