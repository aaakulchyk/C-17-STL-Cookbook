#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_VECTOR_ACCESS_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_VECTOR_ACCESS_H_

#include <iostream>
#include <vector>

void vector_access() {
  constexpr size_t container_size { 1000 };
  std::vector v(container_size, 123);

  // Access out of bounds using operator[] will cause a runtime error
  // std::cout << v[container_size + 10] << '\n';

  // Access it using the at function will cause a runtime error, but with an error message
  std::cout << "Out of range element value: " << v.at(container_size + 10) << '\n';
}

void vector_access_handled() {
  constexpr size_t container_size { 1000 };
  const std::vector v(container_size, 123);

  try {
    std::cout << "Out of range element value: " << v.at(container_size + 10) << '\n';
  } catch (const std::out_of_range& e) {
    std::cerr << "Ooops, out of range access detected: " << e.what() << '\n';
  }

}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_VECTOR_ACCESS_H_
