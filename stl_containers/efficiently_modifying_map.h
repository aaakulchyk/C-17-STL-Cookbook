#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_EFFIIENTLY_MODIFYING_MAP_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_EFFIIENTLY_MODIFYING_MAP_H_

#include <iostream>
#include <map>
#include <string>

template <typename M>
void print(const M& m) {
  std::cout << "Race placement:\n";
  for (const auto& [placement, driver] : m) {
    std::cout << placement << ": " << driver << '\n';
  }
}

void efficiently_modifying_map() {
  std::map<int, std::string> race_placement {
      { 1, "Mario" },
      { 2, "Luigi" },
      { 3, "Bowser" },
      { 4, "Peach" },
      { 5, "Yoshi" },
      { 6, "Koopa" },
      { 7, "Toad" },
      { 8, "Donkey Kong Jr." },
  };

  print(race_placement);

  // Open a new scope to restrict lifetime of temporary variables
  {
    // The `extract` function removes an item without allocation-related effects
    auto a(race_placement.extract(3));
    auto b(race_placement.extract(8));

    // Swap keys
    std::swap(a.key(), b.key());

    // Use new overload of `insert` function
    race_placement.insert(std::move(a));
    race_placement.insert(std::move(b));
  }

  print(race_placement);
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_EFFIIENTLY_MODIFYING_MAP_H_
