#ifndef C__17_STL_COOKBOOK_ITERATORS_REVERSE_ITERATOR_ADAPTERS_H_
#define C__17_STL_COOKBOOK_ITERATORS_REVERSE_ITERATOR_ADAPTERS_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

void reverse_iterator_adapters() {
  std::list<int> list { 1, 2, 3, 4, 5 };

  // Print the list in reversed order using `rbegin` and `rend`
  std::copy(
      list.rbegin(),
      list.rend(),
      std::ostream_iterator<int> { std::cout, ", " }
  );
  std::cout << '\n';

  // Convert common iterators into reverse iterators using `std::make_reverse_iterator`
  std::copy(
      std::make_reverse_iterator(std::end(list)),
      std::make_reverse_iterator(std::begin(list)),
      std::ostream_iterator<int> { std::cout, ", " }
  );
}

#endif // C__17_STL_COOKBOOK_ITERATORS_REVERSE_ITERATOR_ADAPTERS_H_
