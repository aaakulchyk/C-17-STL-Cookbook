#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_FINDING_ITEMS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_FINDING_ITEMS_H_

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct City {
  std::string name;
  unsigned population;
}; // struct City

bool operator==(const City& a, const City& b) {
  return a.name == b.name && a.population == b.population;
}

std::ostream& operator<<(std::ostream& os, const City& city) {
  return os << "{ " << city.name << ", " << city.population << " }";
}

template <typename C>
static auto opt_print(const C& container) {
  return [end_it(std::end(container))](const auto& item) {
    item != end_it
    ? std::cout << *item << '\n'
    : std::cout << "<end>\n";
  };
}

void finding_items() {
  const std::vector<City> c {
      { "Aachen", 246000 },
      { "Berlin", 3502000 },
      { "Braunschweig", 251000 },
      { "Cologne", 1060000 },
  };

  auto print_city(opt_print(c));
  {
    auto found_cologne(std::find(std::begin(c), std::end(c), City { "Cologne", 1060000 }));
    print_city(found_cologne);
  }

  {
    auto found_cologne(std::find_if(std::begin(c), std::end(c), [](const auto& item) {
      return item.name == "Cologne";
    }));
    print_city(found_cologne);
  }

  {
    auto population_more_than([](unsigned i) {
      return [=](const City& item) {
        return item.population > i;
      };
    });
    auto found_large(std::find_if(std::begin(c), std::end(c), population_more_than(2000000)));
    print_city(found_large);
  }

  const std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  auto print_int(opt_print(v));
  bool contains_7 { std::binary_search(std::begin(v), std::end(v), 7) };
  std::cout << contains_7 << '\n';
  auto [lower_it, upper_it](std::equal_range(std::begin(v), std::end(v), 7));
  print_int(lower_it);
  print_int(upper_it);
  print_int(std::lower_bound(std::begin(v), std::end(v), 7));
  print_int(std::upper_bound(std::begin(v), std::end(v), 7));
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_FINDING_ITEMS_H_
