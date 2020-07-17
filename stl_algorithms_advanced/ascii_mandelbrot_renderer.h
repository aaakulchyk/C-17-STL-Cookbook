#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_ASCII_MANDELBROT_RENDERER_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_ASCII_MANDELBROT_RENDERER_H_

#include <algorithm>
#include <complex>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using cmplx = std::complex<double>;

static auto scaler(int min_from, int max_from, double min_to, double max_to) {
  const int    w_from   { max_from - min_from };
  const double w_to     { max_to - min_to };
  const int    mid_from { (max_from - min_from) / 2 + min_from };
  const double mid_to   { (max_to - min_to) / 2.0 + min_to };
  return [=](int from) {
    return static_cast<double>(from - mid_from) / w_from * w_to + mid_to;
  };
}

template <typename A, typename B>
static auto scaled_cmplx(A scaler_x, B scaler_y) {
  return [=](int x, int y) {
    return cmplx { scaler_x(x), scaler_y(y) };
  };
}

static auto mandelbrot_iterations(cmplx c) {
  cmplx z {};
  size_t iterations { 0 };
  const size_t max_iterations { 1000 };
  while (std::abs(z) < 2 && iterations < max_iterations) {
    ++iterations;
    z = std::pow(z, 2) + c;
  }
  return iterations;
}

void ascii_mandelbrot_renderer() {
  constexpr size_t w { 100 };
  constexpr size_t h { 40 };
  auto scale(scaled_cmplx(
      scaler(0, w, -2.0, 1.0),
      scaler(0, h, -1.0, 1.0)
  ));

  auto i2xy([=](int i) { return scale(i % w, i / w); });

  auto to_iteration_count([=](int i) { return mandelbrot_iterations(i2xy(i)); });

  std::vector<int> v(w * h);
  std::iota(std::begin(v), std::end(v), 0);
  std::transform(std::begin(v), std::end(v), std::begin(v), to_iteration_count);

  auto binfunc([w, n { 0 }](auto output_it, int x) mutable {
    *++output_it = (x > 50 ? '*' : ' ');
    if (++n % w == 0) {
      ++output_it = '\n';
    }
    return output_it;
  });

  std::accumulate(std::begin(v), std::end(v), std::ostream_iterator<char> { std::cout }, binfunc);
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_ADVANCED_ASCII_MANDELBROT_RENDERER_H_
