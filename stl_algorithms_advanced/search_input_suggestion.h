#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_SEARCH_INPUT_SUGGESTION_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_SEARCH_INPUT_SUGGESTION_H_

#include <fstream>
#include <list>
#include <sstream>

#include "implementing_trie.h"

static void prompt() {
  std::cout << "Next input please:\n > ";
}

void search_input_suggestion() {
  // Construct a trie
  Trie<std::string> t;
  std::fstream infile { "db.txt" };
  if (infile.is_open())
    for (std::string line; std::getline(infile, line);) {
      std::istringstream iss { line };
      t.Insert(std::istream_iterator<std::string> { iss }, {});
    }

  prompt();
  for (std::string line; std::getline(std::cin, line);) {
    std::istringstream iss { line };
    if (auto st { t.Subtrie(std::istream_iterator<std::string> { iss }, {}) }; st) {
      std::cout << "Suggestions:\n";
      st->get().Print();
    } else {
      std::cout << "No suggestion found.\n";
    }
    std::cout << "----------------\n";
    prompt();
  }
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_SEARCH_INPUT_SUGGESTION_H_
