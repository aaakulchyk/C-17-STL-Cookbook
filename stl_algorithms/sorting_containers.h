#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_SORTING_CONTAINERS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_SORTING_CONTAINERS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

static void print(const std::vector<int>& v) {
  std::copy(std::begin(v), std::end(v), std::ostream_iterator<int> { std::cout, ", " });
  std::cout << '\n';
}

struct mystruct {
  int a;
  int b;
};

void sorting_containers() {
  std::vector v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  // Create a random generator
  std::random_device rd;
  std::mt19937 g { rd() };
  std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';

  // Permute the vector
  std::shuffle(std::begin(v), std::end(v), g);
  std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';
  print(v);

  // Reestablish the original items order
  std::sort(std::begin(v), std::end(v));
  std::cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';
  print(v);

  // Move all items < 5 to the front
  std::shuffle(std::begin(v), std::end(v), g);
  std::partition(std::begin(v), std::end(v), [](const int i) { return i < 5; });
  print(v);

  // Put the N smallest of all vector elements in the first half of the vector in a sorted order
  std::shuffle(std::begin(v), std::end(v), g);
  auto middle(std::next(std::begin(v), static_cast<int>(v.size()) / 2));
  std::partial_sort(std::begin(v), middle, std::end(v));
  print(v);

  // Sort with a predicate
  std::vector<mystruct> mv {
      { 5, 100 }, { 1, 50 }, { -123, 1000 }, { 3, 70 }, { -10, 20 }
  };
  std::sort(std::begin(mv), std::end(mv),
      [](const mystruct& lhs, const mystruct& rhs) {
    return lhs.b < rhs.b;
  });
  for (const auto& [a, b] : mv)
    std::cout << "{ " << a << ", " << b << " } ";
  std::cout << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_SORTING_CONTAINERS_H_
