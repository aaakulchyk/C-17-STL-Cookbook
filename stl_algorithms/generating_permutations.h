#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_GENERATING_PERMUTATIONS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_GENERATING_PERMUTATIONS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void generating_permutations() {
  std::vector<std::string> v { std::istream_iterator<std::string> { std::cin }, {} };
  std::sort(std::begin(v), std::end(v));

  do {
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<std::string> { std::cout, ", " });
    std::cout << '\n';
  } while (std::next_permutation(std::begin(v), std::end(v)));
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_GENERATING_PERMUTATIONS_H_
