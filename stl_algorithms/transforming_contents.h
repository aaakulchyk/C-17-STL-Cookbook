#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_TRANSFORMING_CONTENTS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_TRANSFORMING_CONTENTS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

void transforming_contents() {
  std::vector v { 1, 2, 3, 4, 5 };

  // Apply a transformation to each element of the container
  std::transform(std::begin(v), std::end(v), std::ostream_iterator<int> { std::cout, ", " },
      [](const int i) { return i * i; });
  std::cout << '\n';

  // Generate a nicely readable string
  auto int2str([](const int i) {
    std::stringstream ss;
    ss << i << "^2 = " << i * i;
    return ss.str();
  });
  std::vector<std::string> vs;
  std::transform(std::begin(v), std::end(v), std::back_inserter(vs), int2str);
  for (const auto& s : vs)
    std::cout << s << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_TRANSFORMING_CONTENTS_H_
