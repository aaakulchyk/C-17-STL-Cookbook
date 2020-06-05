#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_KEEP_VECTOR_SORTED_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_KEEP_VECTOR_SORTED_H_

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename C, typename T>
void insert_sorted(C& c, const T& item) {
  const auto insert_pos(std::lower_bound(std::begin(c), std::end(c), item));
  c.insert(insert_pos, item);
}

void keep_vector_sorted() {
  // Initialize a vector
  std::vector<std::string> v { "some", "body", "once", "told", "me" };

  // Sort initial vector
  assert(!std::is_sorted(std::begin(v), std::end(v)));
  std::sort(std::begin(v), std::end(v));
  assert(std::is_sorted(std::begin(v), std::end(v)));

  // Insert new objects in a proper position
  insert_sorted(v, "ham");
  insert_sorted(v, "zulu");

  // Print out vector
  for (const auto& s : v)
    std::cout << s << ' ';
  std::cout << std::endl;
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_KEEP_VECTOR_SORTED_H_
