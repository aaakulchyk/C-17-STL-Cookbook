#ifndef C__17_STL_COOKBOOK_ITERATORS_ZIP_ITERATOR_H_
#define C__17_STL_COOKBOOK_ITERATORS_ZIP_ITERATOR_H_

#include <iostream>
#include <numeric>
#include <vector>

class ZipIterator {
  using it_type = std::vector<double>::iterator;

 public:
  ZipIterator(it_type it1, it_type it2)
  : it1_ { it1 }, it2_ { it2 } {}

  // Incrementing zip iterator means incrementing both iterators
  ZipIterator& operator++() {
    ++it1_;
    ++it2_;
    return *this;
  }

  // Two zip iterators are unequal if both the member iterators are unequal to their counterparts
  bool operator!=(const ZipIterator& o) const {
    return it1_ != o.it1_ && it2_ != o.it2_;
  }

  bool operator==(const ZipIterator& o) const {
    return !(*this != o);
  }

  // Dereferencing the zip iterator gives access to the elements of both the containers at the same point
  [[nodiscard]] std::pair<double, double> operator*() const {
    return { *it1_, *it2_ };
  }

 private:
  it_type it1_;
  it_type it2_;

}; // class ZipIterator

// Make the iterator compatible with STL algorithms
namespace std {

template <>
struct iterator_traits<ZipIterator> {
  using iterator_category = std::forward_iterator_tag;
  using value_type = std::pair<double, double>;
  using difference_type = long int;
}; // struct iterator_traits<ZipIterator>

} // namespace std

// Define a range class
class zip {
 using vec_type = std::vector<double>;
 public:
  zip(vec_type& va, vec_type& vb)
  : vec1_ref_ { va }, vec2_ref_ { vb } {}

  [[nodiscard]] ZipIterator begin() const {
    return { std::begin(vec1_ref_), std::begin(vec2_ref_) };
  }

  [[nodiscard]] ZipIterator end() const {
    return { std::end(vec1_ref_), std::end(vec2_ref_) };
  }

 private:
  vec_type& vec1_ref_;
  vec_type& vec2_ref_;

}; // class zip

void zip_iterator() {
  std::vector a { 1.0, 2.0, 3.0 };
  std::vector b { 4.0, 5.0, 6.0 };

  zip zipped { a, b };

  // Sum all the items of the range together
  const auto add_product([](double sum, const auto& p) {
    return sum + p.first * p.second;
  });

  const auto dot_product(std::accumulate(
      std::begin(zipped), std::end(zipped), 0.0, add_product));

  std::cout << dot_product << std::endl;
}

#endif // C__17_STL_COOKBOOK_ITERATORS_ZIP_ITERATOR_H_
