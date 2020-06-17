#ifndef C__17_STL_COOKBOOK_ITERATORS_ITERATOR_ADAPTERS_H_
#define C__17_STL_COOKBOOK_ITERATORS_ITERATOR_ADAPTERS_H_

#include <deque>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

void iterator_adapters() {
  std::istream_iterator<int> itCin { std::cin };
  std::istream_iterator<int> endCin;

  std::deque<int> d;

  // Push to the back of the deque using `std::back_insert_iterator` iterator adapter
  std::copy(itCin, endCin, std::back_inserter(d));

  // Create iterator pointing to the middle of the deque
  auto dequeMiddle(std::next(std::begin(d), static_cast<int>(d.size()) / 2));

  // Insert into the middle of the deque using `std::istream_iterator` and `std::insert_iterator` iterator adapters
  std::istringstream sstr { "123 456 789" };
  std::copy(std::istream_iterator<int> { sstr }, {}, std::inserter(d, dequeMiddle));

  // Push to the front of the deque using `std::front_insert_iterator` iterator adapter
  std::initializer_list<int> il2 { -1, -2, -3 };
  std::copy(std::begin(il2), std::end(il2), std::front_inserter(d));

  // Print out the contents of the deque using `std::ostream_iterator` iterator adapter
  std::copy(std::begin(d), std::end(d), std::ostream_iterator<int> { std::cout, ", " });
  std::cout << std::endl;
}

#endif // C__17_STL_COOKBOOK_ITERATORS_ITERATOR_ADAPTERS_H_
