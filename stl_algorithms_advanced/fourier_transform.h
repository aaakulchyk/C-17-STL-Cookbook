#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_FOURIER_TRANSFORM_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_FOURIER_TRANSFORM_H_

#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <iterator>
#include <numeric>
#include <valarray>
#include <vector>

using cmplx   = std::complex<double>;
using csignal = std::vector<cmplx>;

class NumIterator {
 public:
  explicit NumIterator(size_t position)
  : i_ { position } {}

  size_t operator*() const {
    return i_;
  }

  NumIterator& operator++() {
    ++i_;
    return *this;
  }

  bool operator!=(const NumIterator& other) const {
    return i_ != other.i_;
  }

 private:
  size_t i_;

}; // class NumIterator

csignal _fourier_transform(const csignal& s, bool back = false) {
  csignal t { s.size() };
  const double pol { 2.0 * M_PI * (back ? -1.0 : 1.0) };
  const double div { back ? 1.0 : static_cast<double>(s.size()) };

  auto sum_up([=, &s](size_t j) {
    return [=, &s](cmplx c, size_t k) {
      return c + s[k] * std::polar(1.0, pol * k * j / static_cast<double>(s.size()));
    };
  });

  auto to_ft([=, &s](size_t j) {
    return std::accumulate(NumIterator { 0 }, NumIterator { s.size() },
        cmplx {}, sum_up(j)) / div;
  });

  std::transform(NumIterator { 0 }, NumIterator { s.size() }, std::begin(t), to_ft);
  return t;
}

static auto gen_cosine(size_t period_len) {
  return [period_len, n { 0 }]() mutable {
    return std::cos(static_cast<double>(n++) * 2.0 * M_PI / period_len);
  };
}

static auto gen_square_wave(size_t period_len) {
  return [period_len, n { period_len * 7 / 4 }]() mutable {
    return ((n++ * 2 / period_len % 2)) * 2 - 1.0;
  };
}

template <typename F>
static csignal signal_from_generator(size_t len, F gen) {
  csignal r(len);
  std::generate(std::begin(r), std::end(r), gen);
  return r;
}

static void print_signal(const csignal& s) {
  auto real_val([](cmplx c) { return c.real(); });
  std::transform(std::begin(s), std::end(s), std::ostream_iterator<double> { std::cout, " " }, real_val);
  std::cout << '\n';
}

void fourier_transform() {
  constexpr size_t sig_len { 100 };
  auto cosine(signal_from_generator(sig_len, gen_cosine(sig_len / 2)));
  auto square_wave(signal_from_generator(sig_len, gen_square_wave(sig_len / 2)));
  auto trans_sqw(_fourier_transform(square_wave));
  std::fill(std::next(std::begin(trans_sqw), 10), std::prev(std::end(trans_sqw), 10), 0);
  auto mid(_fourier_transform(trans_sqw, true));

  print_signal(cosine);
  print_signal(_fourier_transform(cosine));
  print_signal(mid);
  print_signal(trans_sqw);
  print_signal(square_wave);
  print_signal(_fourier_transform(square_wave));
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_FOURIER_TRANSFORM_H_
