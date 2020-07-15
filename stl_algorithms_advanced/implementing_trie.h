#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_IMPLEMENTING_TRIE_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_IMPLEMENTING_TRIE_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <string>
#include <vector>

template <typename T>
class Trie {
 public:
  template <typename It>
  void Insert(It it, It end_it) {
    if (it == end_it)
      return;
    tries_[*it].Insert(std::next(it), end_it);
  }

  template <typename C>
  void Insert(const C& container) {
    Insert(std::begin(container), std::end(container));
  }

  void Insert(const std::initializer_list<T>& il) {
    Insert(std::begin(il), std::end(il));
  }

  void Print(std::vector<T>& v) const {
    if (tries_.empty()) {
      std::copy(std::begin(v), std::end(v), std::ostream_iterator<T> { std::cout, " " });
      std::cout << '\n';
    }
    for (const auto& p : tries_) {
      v.push_back(p.first);
      p.second.Print(v);
      v.pop_back();
    }
  }

  void Print() const {
    std::vector<T> v;
    Print(v);
  }

  template <typename It>
  std::optional<std::reference_wrapper<const Trie>> Subtrie(It it, It end_it) const {
    if (it == end_it)
      return std::ref(*this);
    auto found { tries_.find(*it) };
    if (found == std::end(tries_))
      return {};
    return found->second.Subtrie(std::next(it), end_it);
  }

  template <typename C>
  auto Subtrie(const C& container) const {
    return Subtrie(std::begin(container), std::end(container));
  }

 private:
  std::map<T, Trie> tries_;

}; // class Trie

void implementing_trie() {
  Trie<std::string> t;
  t.Insert({ "hi", "how", "are", "you" });
  t.Insert({ "hi", "i", "am", "great", "thanks" });
  t.Insert({ "what", "are", "you", "doing" });
  t.Insert({ "i", "am", "watching", "a", "movie" });

  // Print the whole trie
  std::cout << "Recorded sentences:\n";
  t.Print();

  // Obtain subtrie for all the input sentences that start with "hi"
  std::cout << "\nPossible suggestions after \"hi\":\n";
  if (auto st { t.Subtrie(std::initializer_list<std::string> { "hi" }) }; st) {
    st->get().Print();
  }
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_IMPLEMENTING_TRIE_H_
