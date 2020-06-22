#ifndef C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_DEFINING_LAMBDAS_H_
#define C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_DEFINING_LAMBDAS_H_

#include <iostream>
#include <string>

void defining_lambdas() {
  auto just_one([]() { return 1; });
  auto just_two([] { return 2; });

  std::cout << just_one() << ", " << just_two() << '\n';

  auto plus([](auto l, auto r) { return l + r; });
  std::cout << plus(1, 2) << '\n';
  std::cout << plus(std::string { "a" }, "b") << '\n';

  // We can also define lambdas in place
  std::cout << [](auto l, auto r){ return l + r; }(1,  2) << '\n';

  // Define a closure that carries an integer counter value around with it
  auto counter(
      [counter = 0]() mutable { return ++counter; }
      );
  for (auto i { 0 }; i < 5; ++i)
    std::cout << counter() << ", ";
  std::cout << '\n';

  // Capture external variables by reference
  int a { 0 };
  auto incrementer([&a] { ++a; });

  for (auto i { 0 }; i < 3; ++i)
    incrementer();
  std::cout << "Value of 'a' after 3 incrementer() calls: " << a << '\n';

  // Example of currying
  auto plus_ten([=](int x) { return plus(10, x); });
  std::cout << plus_ten(5) << '\n';
}

#endif // C__17_STL_COOKBOOK_LAMBDA_EXPRESSIONS_DEFINING_LAMBDAS_H_
