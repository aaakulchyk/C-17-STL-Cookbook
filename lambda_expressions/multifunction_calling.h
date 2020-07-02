#ifndef C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_MULTIFUNCTION_CALLING_H_
#define C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_MULTIFUNCTION_CALLING_H_

#include <iostream>

// Return a lambda that will call all ...functions with the same input
template <typename... Fs>
static auto multicall(Fs ...functions) {
  return [=](auto x) {
    (void) std::initializer_list<int> {
        ((void) functions(x), 0)...
    };
  };
}

// Apply f to all ...xs
template <typename F, typename... Args>
static auto for_each(F f, Args ...xs) {
  (void) std::initializer_list<int> {
      ((void) f(xs), 0)...
  };
}

static auto brace_print(const char a, const char b) {
  return [=](auto x) {
    std::cout << a << x << b << ", ";
  };
}

void multifunction_calling() {
  // Define sample functions
  auto f(brace_print('(', ')'));
  auto g(brace_print('[', ']'));
  auto h(brace_print('{', '}'));
  auto nl([](auto) { std::cout << '\n'; });

  auto call_fghnl(multicall(f, g, h, nl));
  for_each(call_fghnl, 1, 2, 3, 4, 5);
}

#endif // C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_MULTIFUNCTION_CALLING_H_
