#ifndef C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_TRANSFORM_IF_H_
#define C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_TRANSFORM_IF_H_

#include <iostream>
#include <iterator>
#include <numeric>

template <typename F>
auto map(F fn) {
  return [=](auto reduce_fn) {
    return [=](auto accum, auto input) {
      return reduce_fn(accum, fn(input));
    };
  };
}

template <typename F>
auto filter(F predicate) {
  return [=](auto reduce_fn) {
    return [=](auto accum, auto input) {
      return predicate(input) ? reduce_fn(accum, input) : accum;
    };
  };
}

void transform_if() {
  std::istream_iterator<int> it { std::cin };
  std::istream_iterator<int> endIt {};

  auto even([](int i) { return i % 2 == 0; });
  auto twice([](int i) { return 2 * i; });

  auto copyAndAdvance([](auto it, auto input) {
    *it = input;
    return ++it;
  });

  std::accumulate(it, endIt,
      std::ostream_iterator<int> { std::cout, ", " },
      filter(even)(
          map(twice)(
              copyAndAdvance
          )
      )
  );

  std::cout << std::endl;
}

#endif // C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_TRANSFORM_IF_H_
