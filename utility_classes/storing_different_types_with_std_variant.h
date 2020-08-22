#ifndef C__17_STL_COOKBOOK_UTILITY_CLASSES_STORING_DIFFERENT_TYPES_WITH_STD_VARIANT_H_
#define C__17_STL_COOKBOOK_UTILITY_CLASSES_STORING_DIFFERENT_TYPES_WITH_STD_VARIANT_H_

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <variant>

// A cat object has a name and can say meow
class Cat {
 public:
  explicit Cat(std::string n) : name_(std::move(n)) {}

  void Meow() const {
    std::cout << name_ << " says Meow!\n";
  }

 private:
  std::string name_ {};

};

// A dog object has name and can say woof
class Dog {
 public:
  explicit Dog(std::string n) : name_(std::move(n)) {}

  void Woof() const {
    std::cout << name_ << " says Woof!\n";
  }

 private:
  std::string name_ {};

};

// Define a pet type as type alias
using Pet = std::variant<Cat, Dog>;

// Implement pet type predicate
template <typename T>
bool is_type(const Pet& p) {
  return std::holds_alternative<T>(p);
}

// Implement a functional struct that calls pet voice
struct PetVoice {
  void operator()(const Cat& cat) { cat.Meow(); }
  void operator()(const Dog& dog) { dog.Woof(); }
};

void storing_different_types_with_std_variant() {
  std::list<Pet> pets { Cat {"Tuba"}, Dog { "Balou" }, Cat { "Bobby" } };

  // Print the contents of the list using std::variant::index
  for (const Pet& pet : pets) {
    switch (pet.index()) {
      case 0: { // Cat goes first in the declaration of Pet std::variant
        std::get<Cat>(pet).Meow();
        break;
      }

      case 1: { // Dog goes second in the declaration of Pet std::variant
        std::get<Dog>(pet).Woof();
        break;
      }
    }
  }

  std::cout << "-----\n";

  // Print the contents of the list explicitly asking for every type
  for (const Pet& pet : pets) {
    if (const auto cat(std::get_if<Cat>(pet)); cat) {
      cat->Meow():
    } else if (const auto dog(std::get_if<Dog>(pet)); dog) {
      dog->Woof();
    }
  }

  std::cout << "-----\n";

  // Print the contents of the list using std::variant::visit
  for (const Pet& pet : pets) {
    std::visit(PetVoice {}, pet);
  }

  std::cout << "-----\n";

  // Count the number of cats and dogs in the variant list
  std::cout << "There are "
    << std::count_if(std::begin(pets), std::end(pets), std::is_type<Cat>)
    << " cats and "
    << std::count_if(std::begin(pets), std::end(pets), std::is_type<Dog>)
    << " dogs in the list.\n";
}

#endif // C__17_STL_COOKBOOK_UTILITY_CLASSES_STORING_DIFFERENT_TYPES_WITH_STD_VARIANT_H_
