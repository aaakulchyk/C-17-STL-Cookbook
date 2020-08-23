#ifndef C__17_STL_COOKBOOK_UTILITY_CLASSES_UNIQUE_PTR_H_
#define C__17_STL_COOKBOOK_UTILITY_CLASSES_UNIQUE_PTR_H_

/**
 * A unique pointer expresses ownership of the object it points to and follows its responsibility of freeing its memory
 * again if it is no longer used. This class has the potential of relieving us forever from memory leaks. And the best
 * thing is that it imposes no overhead on space and runtime performance, compared with code with raw pointers and
 * manual memory management.
 */

#include <iostream>
#include <memory>

class Foo {
 public:
  std::string name_;

  explicit Foo(std::string name) : name_(std::move(name)) {
    std::cout << "CTOR " << name_ << '\n';
  }

  ~Foo() {
    std::cout << "DTOR " << name_ << '\n';
  }

}; // class Foo

// Implement a function that accepts unique pointer as argument to see what limitations it has
void process_item(std::unique_ptr<Foo> p) {
  if (!p) return;
  std::cout << "Processing " << p->name_ << '\n';
}

void unique_ptr() {
  // Create two Foo objects on the heap and manage both with unique pointers
  {
    std::unique_ptr<Foo> p1 { new Foo { "foo" } };
    auto p2(std::make_unique<Foo>("bar"));
  }

  // If we construct a new Foo instance, managed by a unique_ptr in the function call, then its lifetime is reduced to
  // the scope of the function. When process_item returns, the object is destroyed.
  process_item(std::make_unique<Foo>("foo1"));

  // If we want to call process_item with an object that already existed before the call, then we need to transfer
  // ownership because that function takes a unique_ptr by value, which means that calling it would lead to a copy.
  // But unique_ptr cannot be copied, it can only be moved. When we transfer ownership, the lifetime of the object will
  // be again reduced to the scope of the function.
  auto p1(std::make_unique<Foo>("foo2"));
  auto p2(std::make_unique<Foo>("foo3"));
  process_item(std::move(p1));
  std::cout << "End of main()\n";
}

#endif // C__17_STL_COOKBOOK_UTILITY_CLASSES_UNIQUE_PTR_H_
