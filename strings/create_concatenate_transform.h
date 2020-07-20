#ifndef C__17_STL_COOKBOOK_STRINGS_CREATE_CONCATENATE_TRANSFORM_H_
#define C__17_STL_COOKBOOK_STRINGS_CREATE_CONCATENATE_TRANSFORM_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

void create_concatenate_transform() {
  std::string a { "a" };
  // Doesn't work auto b("b"s);
  std::string b { "b" };

  std::string_view c { "c" };
  // Doesn't work auto d("d"sv);
  std::string_view d { "d" };

  std::cout << a << ", " << b << '\n';
  std::cout << c << ", " << d << '\n';

  std::cout << a + b << '\n';
  std::cout << a + std::string { "c" } << '\n';

  std::ostringstream o;
  o << a << " " << b << " " << c << " " << d;
  auto concatenated(o.str());
  std::cout << concatenated << '\n';

  std::transform(std::begin(concatenated), std::end(concatenated), std::begin(concatenated), ::toupper);
  std::cout << concatenated << '\n';
}

#endif // C__17_STL_COOKBOOK_STRINGS_CREATE_CONCATENATE_TRANSFORM_H_
