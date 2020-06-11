#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_RPN_CALCULATOR_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_RPN_CALCULATOR_H_

#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>

// Implement a helper for more convenient access to stack top element
static inline auto pop_stack([](std::stack<double>& values_stack) {
  auto r(values_stack.top());
  values_stack.pop();
  return r;
});

template <typename It>
double evaluate_rpn(It it, It end) {
  std::stack<double> values_stack;

  // Define all the supported mathematical operations
  const std::map<std::string, double (*)(double, double)> ops {
      { "+", [](double a, double b) { return a + b; } },
      { "-", [](double a, double b) { return a - b; } },
      { "*", [](double a, double b) { return a * b; } },
      { "/", [](double a, double b) { return a / b; } },
      { "^", [](double a, double b) { return std::pow(a, b); } },
      { "%", [](double a, double b) { return std::fmod(a, b); } },
  };

  for (; it != end; ++it) {
    std::stringstream ss { *it };

    // Try to push a double value onto the stack
    if (double val; ss >> val) {
      values_stack.push(val);
    } else {
      const auto r{pop_stack(values_stack)};
      const auto l{pop_stack(values_stack)};

      // Get the lambda object for an operation
      try {
        const auto &op(ops.at(*it));
        const double result { op(l, r) };
        values_stack.push(result);
      } catch (const std::out_of_range &) {
        throw std::invalid_argument(*it);
      }
    }
  }

  // The final result is stored on the stack
  return values_stack.top();
}

void rpn_calculator() {
  try {
    std::cout << evaluate_rpn(std::istream_iterator<std::string> { std::cin }, {}) << '\n';

    std::stringstream s { "3 2 1 + * 2 /" };
    std::cout << evaluate_rpn(std::istream_iterator<std::string> { s }, {}) << '\n';

    std::vector<std::string> v { "3", "2", "1", "+", "*", "2", "/" };
    std::cout << evaluate_rpn(std::begin(v), std::end(v)) << '\n';
  } catch (const std::invalid_argument& e) {
    std::cout << "Invalid operator: " << e.what();
  }
  std::flush(std::cout);
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_RPN_CALCULATOR_H_
