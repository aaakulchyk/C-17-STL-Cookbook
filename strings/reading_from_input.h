#ifndef C__17_STL_COOKBOOK_STRINGS_READING_FROM_INPUT_H_
#define C__17_STL_COOKBOOK_STRINGS_READING_FROM_INPUT_H_

#include <iostream>

void reading_from_input() {
  std::cout << "Please enter two numbers:\n>";
  int x;
  double y;

  if (std::cin >> x >> y) {
    std::cout << "You entered: " << x << " and " << y << '\n';
  } else {
    std::cout << "Oh no, that did not go well!\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  std::cout << "Now please enter some comma-separated names:\n>";
  for (std::string s; std::getline(std::cin >> s, s, ',');) {
    if (s.empty()) break;
    std::cout << "Name: \"" << s << "\"\n";
  }
}

#endif // C__17_STL_COOKBOOK_STRINGS_READING_FROM_INPUT_H_
