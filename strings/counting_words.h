#ifndef C__17_STL_COOKBOOK_STRINGS_COUNTING_WORDS_H_
#define C__17_STL_COOKBOOK_STRINGS_COUNTING_WORDS_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

template <typename T>
size_t wordcount(T& is) {
  return std::distance(std::istream_iterator<std::string> { is }, {});
}

void counting_words(int argc, char* argv[]) {
  size_t wc;
  if (argc == 2) {
    std::ifstream ifs { argv[1] };
    wc = wordcount(ifs);
  } else {
    wc = wordcount(std::cin);
  }
  std::cout << "There are " << wc << " words\n";
}

#endif // C__17_STL_COOKBOOK_STRINGS_COUNTING_WORDS_H_
