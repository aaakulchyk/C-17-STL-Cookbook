#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_REMOVING_SPECIFIC_ITEMS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_REMOVING_SPECIFIC_ITEMS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

static void print(const std::vector<int>& v) {
  std::copy(std::begin(v), std::end(v), std::ostream_iterator<int> { std::cout, ", " });
  std::cout << '\n';
}

void removing_specific_items() {
  std::vector v { 1, 2, 3, 4, 5, 6 };
  print(v);

  // Remove all the items with the value 2
  {
    const auto new_end(std::remove(std::begin(v), std::end(v), 2));
    v.erase(new_end, std::end(v));
  }
  print(v);

  // Remove all the odd numbers
  {
    auto odd_number([](const int i) -> bool { return i % 2 != 0; });
    const auto new_end(std::remove_if(std::begin(v), std::end(v), odd_number));
    v.erase(new_end, std::end(v));
  }
  print(v);

  // Overwrite all values of 4 with the value 123
  std::replace(std::begin(v), std::end(v), 4, 123);
  print(v);

  v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> v2;
  std::vector<int> v3;
  auto odd_number([](const int i) -> bool { return i % 2 != 0; });
  auto even_number([](const int i) -> bool { return i % 2 == 0; });
  std::remove_copy_if(std::begin(v), std::end(v), std::back_inserter(v2), odd_number);
  std::copy_if(std::begin(v), std::end(v), std::back_inserter(v3), even_number);
  print(v2);
  print(v3);
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_REMOVING_SPECIFIC_ITEMS_H_
