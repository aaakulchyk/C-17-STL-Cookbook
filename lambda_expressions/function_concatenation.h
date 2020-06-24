#ifndef C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_FUNCTION_CONCATENATION_H_
#define C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_FUNCTION_CONCATENATION_H_

#include <functional>
#include <iostream>

template <typename T, typename ...Ts>
auto concat(T t, Ts ...ts) {
  if constexpr (sizeof...(ts) > 0) {
    // If there are ts, recursively concatenate them into t(concat(ts))
    return [=](auto ...parameters) {
      return t(concat(ts...)(parameters...));
    };
  } else {
    // Otherwise it is the base case, so just return
    return t;
  }
}

void function_concatenation() {
  auto twice([](int i) { return i * 2; });
  auto thrice([](int i) { return i * 3; });

  // Concatenate above functions with std::plus into twice(thrice(a + b))
  auto combined(concat(twice, thrice, std::plus<int>{}));

  std::cout << combined(2, 3) << std::endl;
}

#endif // C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_FUNCTION_CONCATENATION_H_
