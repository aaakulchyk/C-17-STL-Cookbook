#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_MAP_INSERTION_HINT_SEMANTICS_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_MAP_INSERTION_HINT_SEMANTICS_H_

#include <iostream>
#include <map>
#include <string>

void map_insertion_hint_semantics() {
  std::map<std::string, size_t> map {
      { "b", 1 },
      { "c", 2 },
      { "d", 3 },
  };

  // Start with end iterator hint
  auto insert_it(std::end(map));

  // The next item will be inserted just before the hint
  for (const auto& s: { "s", "y", "x", "w" }) {
    insert_it = map.insert(insert_it, { s, 1 });
  }

  // Insertion is not done with wrong hint
  map.insert(std::end(map), { "a", 1 });

  // Print out what we have
  for (const auto& [key, value] : map)
    std::cout << "\"" << key << "\":" << value << ", ";
  std::cout << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_MAP_INSERTION_HINT_SEMANTICS_H_
