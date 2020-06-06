#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_INSERTING_INTO_MAP_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_INSERTING_INTO_MAP_H_

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>

struct Billionaire {
  std::string name;
  double dollars;
  std::string country;
}; // struct Billionaire

void inserting_into_map() {
  // Define a list of billionaires
  std::list<Billionaire> billionaires {
      { "Bill Gates", 86.0, "USA" },
      { "Warren Buffet", 75.6, "USA" },
      { "Jeff Bezos", 72.8, "USA" },
      { "Amancio Ortega", 71.3, "Spain" },
      { "Mark Zuckerberg", 56.0, "USA" },
      { "Carlos Slim", 54.5, "Mexico" },
      { "Bernard Arnault", 41.5, "France" },
      { "Liliane Bettencourt", 39.5, "France" },
      { "Elon Musk", 38.7, "USA" },
      { "Wang Jianlin", 31.3, "China" },
      { "Li Ka-shing", 31.2, "Hong Kong" },
  };

  // Define a map of billionaires, given the list
  std::map<std::string, std::pair<const Billionaire, size_t>> map;

  // Go through the list and try to emplace a new payload pair
  for (const auto& b : billionaires) {
    auto [it, success] = map.try_emplace(b.country, b, 1);
    if (!success) {
      it->second.second += 1;
    }
  }

  // Print out the number of billionaires per country, and who is the wealthiest in each country
  for (const auto& [key, value] : map) {
    const auto& [b, count] = value;
    std::cout << b.country << ": " << count << " billionaires. The richest is "
        << b.name << " with " << b.dollars << " B$.\n";
  }
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_INSERTING_INTO_MAP_H_
