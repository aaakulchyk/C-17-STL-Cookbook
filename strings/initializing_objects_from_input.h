#ifndef C__17_STL_COOKBOOK_STRINGS_INITIALIZING_OBJECTS_FROM_INPUT_H_
#define C__17_STL_COOKBOOK_STRINGS_INITIALIZING_OBJECTS_FROM_INPUT_H_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// Define a complex object
struct City {
  std::string name;
  size_t population;
  double latitude;
  double longitude;
};

// Overload operator>> in order to read such a city from a serial input stream
std::istream& operator>>(std::istream& is, City& c) {
  is >> std::ws;
  std::getline(is, c.name);
  is >> c.population
      >> c.latitude
      >> c.longitude;
  return is;
}

void initializing_objects_from_input() {
  std::vector<City> l;
  std::copy(std::istream_iterator<City> { std::cin }, {}, std::back_inserter(l));
  for (const auto& [name, pop, lat, lon] : l) {
    std::cout << std::left << std::setw(15) << name
        << " population=" << pop
        << " lat=" << lat
        << " lon=" << lon << '\n';
  }
}

#endif // C__17_STL_COOKBOOK_STRINGS_INITIALIZING_OBJECTS_FROM_INPUT_H_
