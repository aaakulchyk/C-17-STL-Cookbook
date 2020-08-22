#ifndef C__17_STL_COOKBOOK_UTILITY_CLASSES_REPLACING_VOID_PTR_WITH_STD_ANY_H_
#define C__17_STL_COOKBOOK_UTILITY_CLASSES_REPLACING_VOID_PTR_WITH_STD_ANY_H_

#include <any>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>

// Implement a function that claims to be able to print anything.
void print_anything(const std::any& a) {

  // First check whether an instance contains anything
  if (!a.has_value()) {
    std::cout << "<NULL>\n";
    // Otherwise we can try to compare it with different types
  } else if (a.type() == typeid(std::string)) {
    std::cout << "<std::string>: " << std::quoted(std::any_cast<const std::string&>(a)) << '\n';
    // If it's not a string, maybe it's an int
  } else if (a.type() == typeid(int)) {
    std::cout << "<int>: " << std::any_cast<int>(a) << '\n';
    // We can also put whatever complex type
  } else if (a.type() == typeid(std::list<int>)) {
    const auto& l(std::any_cast<std::list<int>>(a));
    std::cout << "<std::list<int>>: ";
    std::copy(std::begin(l), std::end(l), std::ostream_iterator<int> { std::cout, ", " });
    std::cout << '\n';
    // If none of these types match, we run out of type guesses
  } else {
    std::cout << "Can't handle this item.\n";
  }
}

// In the main function we can call `print_anything` with arbitrary types
void replacing_void_ptr_with_std_any() {
  print_anything({});
  print_anything(std::string("abc"));
  print_anything(123);
  print_anything(std::list<int> { 1, 2, 3 });

  // If we are going to put objects that are really expensive to copy into an any
  // variable, we can also perform an in-place construction. Let's try this with our
  // list type.
  print_anything(std::any(std::in_place_type_t<std::list<int>>{}, {1, 2, 3}));
}

#endif // C__17_STL_COOKBOOK_UTILITY_CLASSES_REPLACING_VOID_PTR_WITH_STD_ANY_H_
