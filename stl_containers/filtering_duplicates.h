#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_FILTERING_DUPLICATES_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_FILTERING_DUPLICATES_H_

#include <iostream>
#include <iterator>
#include <set>
#include <string>

void filtering_duplicates() {
  // Define a set
  std::set<std::string> set;

  // Use istream_iterator to get user's input
  std::istream_iterator<std::string> it { std::cin };
  std::istream_iterator<std::string> end;
  std::copy(it, end, std::inserter(set, set.end()));

  // Output unique words
  for (const auto& word : set)
    std::cout << word << ", ";
  std::cout << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_FILTERING_DUPLICATES_H_
