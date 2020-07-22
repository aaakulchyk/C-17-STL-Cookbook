#ifndef C__17_STL_COOKBOOK_STRINGS_COMFORT_WITHOUT_CONSTRUCTING_H_
#define C__17_STL_COOKBOOK_STRINGS_COMFORT_WITHOUT_CONSTRUCTING_H_

#include <iostream>
#include <string_view>

static void print(std::string_view v) {
  // Trim from the beginning
  const auto words_begin(v.find_first_not_of(" \t\n"));
  v.remove_prefix(std::min(words_begin, v.size()));

  // Trim from the end
  const auto words_end(v.find_last_not_of(" \t\n"));
  if (words_end != std::string_view::npos) {
    v.remove_suffix(v.size() - words_end - 1);
  }

  // Actually print
  std::cout << "length: " << v.length() << " [" << v << "]\n";
}

void comfort_without_constructing(int argc, char* argv[]) {
  print(argv[0]);
  print({});
  print("a const char * array");

  // The following two do not work with G++9
  // print("an std::string_view literal"sv);
  // print("an std::string instance"s);

  print(" \t\n foobar \n \t ");
  char cstr[] { 'a', 'b', 'c' };
  print(std::string_view(cstr, sizeof(cstr)));
}

#endif // C__17_STL_COOKBOOK_STRINGS_COMFORT_WITHOUT_CONSTRUCTING_H_
