#ifndef C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_WRAPPING_LAMBDAS_H_
#define C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_WRAPPING_LAMBDAS_H_

#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

/**
 * Little function that returns a lambda expression. It accepts a container and returns a function object that captures
 * that container by reference. The function itself accepts an integer parameter.
 */
template <typename C>
static auto consumer(C& container) {
  return [&](auto value) {
    container.push_back(value);
  };
}

template <typename C>
static void print(const C& c) {
  for (auto i : c) {
    std::cout << i << ", ";
  }
  std::cout << '\n';
}

void wrapping_lambdas() {
  std::deque<int> d;
  std::list<int> l;
  std::vector<int> v;

  // Produce consumer function objects and store them all in a vector instance
  const std::vector<std::function<void(int)>> consumers {
    consumer(d), consumer(l), consumer(v),
  };

  // Feed 10 integers to all the data structures
  for (auto i { 0 }; i < 10; ++i)
    for (auto&& consume : consumers)
      consume(i);

  // All the three containers should contain the same 10 number values
  print(d);
  print(l);
  print(v);
}

#endif // C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_WRAPPING_LAMBDAS_H_
