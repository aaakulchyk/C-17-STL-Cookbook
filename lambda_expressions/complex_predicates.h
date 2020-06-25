#ifndef C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_COMPLEX_PREDICATES_H_
#define C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_COMPLEX_PREDICATES_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

// Implement two simple predicate functions
static bool begins_with_a(const std::string& s) {
  return s.find('a') == 0;
}

static bool ends_with_b(const std::string& s) {
  return s.find('b') == s.length() - 1;
}

// Implement helper function which combines predicates
template <typename A, typename B, typename F>
auto combine(F binaryFunc, A a, B b) {
  return [=](auto param) {
    return binaryFunc(a(param), b(param));
  };
}

void complex_predicates() {
  auto a_xxx_b(combine(
      std::logical_and<>{},
      begins_with_a,
      ends_with_b
  ));

  std::copy_if(
      std::istream_iterator<std::string> { std::cin }, {},
      std::ostream_iterator<std::string> { std::cout, ", " },
      a_xxx_b
  );
}

#endif // C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_COMPLEX_PREDICATES_H_
