#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_WORD_FREQUENCY_COUNTER_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_WORD_FREQUENCY_COUNTER_H_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string filter_punctuation(const std::string& s) {
  const char* forbidden { ".,:; " };
  const auto kIdxStart(s.find_first_not_of(forbidden));
  const auto kIdxEnd(s.find_last_not_of(forbidden));
  return s.substr(kIdxStart, kIdxEnd - kIdxStart + 1);
}

void word_frequency_counter() {
  std::map<std::string, size_t> words;
  int maxWordLen { 0 };
  std::string s;

  while (std::cin >> s) {
    auto filtered(filter_punctuation(s));
    maxWordLen = std::max<int>(maxWordLen, filtered.length());
    ++words[filtered];
  }

  std::vector<std::pair<std::string, size_t>> wordCounts;
  wordCounts.reserve(words.size());
  std::move(std::begin(words), std::end(words), std::back_inserter(wordCounts));
  std::sort(std::begin(wordCounts), std::end(wordCounts),
      [](const auto& a, const auto& b) {
        return a.second > b.second;
  });

  std::cout << "# " << std::setw(maxWordLen) << "<WORD>" << "#<COUNT>\n";
  for (const auto& [word, count] : wordCounts) {
    std::cout << std::setw(maxWordLen + 2) << word << " #" << count << '\n';
  }
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_WORD_FREQUENCY_COUNTER_H_
