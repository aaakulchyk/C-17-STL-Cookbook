#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_UNORDERED_MAP_WITH_CUSTOM_TYPES_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_UNORDERED_MAP_WITH_CUSTOM_TYPES_H_

#include <iostream>
#include <unordered_map>

// Define a custom structure
struct Coord {
  int x;
  int y;

  // It needs to be comparable
  friend bool operator==(const Coord& a, const Coord& b) {
    return a.x == b.x && a.y == b.y;
  }
}; // struct Coord

// Extend the STL's own hashing capabilities
namespace std {

template <>
struct hash<Coord> {
  using argument_type = Coord;
  using result_type = size_t;

  result_type operator()(const argument_type& c) const {
    return static_cast<result_type>(c.x) + static_cast<result_type>(c.y);
  }
}; // struct hash<Coord>

} // namespace std

void unordered_map_with_custom_types() {
  std::unordered_map<Coord, int> m {{{0, 0}, 1}, {{0, 1}, 2}, {{2, 1}, 3}};

  for (const auto& [key, value] : m)
    std::cout << "{(" << key.x << ", " << key.y << "):" << value << "} ";
  std::cout << std::endl;
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_UNORDERED_MAP_WITH_CUSTOM_TYPES_H_
