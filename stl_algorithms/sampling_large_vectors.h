#ifndef C__17_STL_COOKBOOK_STL_ALGORITHMS_SAMPLING_LARGE_VECTORS_H_
#define C__17_STL_COOKBOOK_STL_ALGORITHMS_SAMPLING_LARGE_VECTORS_H_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <random>
#include <vector>

void sampling_large_vectors() {
  constexpr size_t data_points { 100000 };
  constexpr size_t sample_points { 100 };
  constexpr int mean { 10 };
  constexpr size_t dev { 3 };

  std::random_device rd;
  std::mt19937 gen { rd() };
  std::normal_distribution<> d { mean, dev };

  // Instantiate a vector and fill it with random numbers
  std::vector<int> v;
  v.reserve(data_points);
  std::generate_n(std::back_inserter(v), data_points, [&] { return d(gen); });

  // Instantiate another vector that will contain the much smaller set of samples
  std::vector<int> samples;
  samples.reserve(sample_points);
  std::sample(std::begin(v), std::end(v), std::back_inserter(samples),
      sample_points, std::mt19937 { std::random_device{}() });

  // Create a histogram
  std::map<int, size_t> hist;
  for (auto i : samples)
    ++hist[i];
  for (const auto& [value, count] : hist)
    std::cout << std::setw(2) << value << " " << std::string(count, '*') << '\n';
}

#endif // C__17_STL_COOKBOOK_STL_ALGORITHMS_SAMPLING_LARGE_VECTORS_H_
