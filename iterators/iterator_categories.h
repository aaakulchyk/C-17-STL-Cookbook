#ifndef C__17_STL_COOKBOOK_ITERATORS_ITERATOR_CATEGORIES_H_
#define C__17_STL_COOKBOOK_ITERATORS_ITERATOR_CATEGORIES_H_

#include <algorithm>
#include <iostream>

#include "iterable_range.h"

void iterator_categories() {
  NumRange r { 100, 110 };

  // Find minimum and maximum elements
  auto [minIt, maxIt] (std::minmax_element(std::begin(r), std::end(r)));

  // Print out the results
  std::cout << *minIt << " - " << *maxIt << std::endl;
}

#endif // C__17_STL_COOKBOOK_ITERATORS_ITERATOR_CATEGORIES_H_
