#ifndef C__17_STL_COOKBOOK_UTILITY_CLASSES_WEAK_PTR_H_
#define C__17_STL_COOKBOOK_UTILITY_CLASSES_WEAK_PTR_H_

/**
 * Whenever we copy shared_ptr, we increment its internal reference counter. As long as we hold our shared pointer
 * copy, the object being pointed to will not be deleted. But what if we want some kind of weak pointer, which enables
 * us to get at the object as long as it exists but does not prevent its destruction? And how do we determine if the
 * object still exists, then?
 */

#include <iostream>
#include <iomanip>
#include <memory>

struct Foo {
  int value;
  explicit Foo(int i) : value { i } {}
  ~Foo() { std::cout << "DTOR Foo " << value << '\n'; }
}; // struct Foo

// Implement function that prints information about a weak pointer, so we can print a weak pointer's state at different
// points of our program
void weak_ptr_info(const std::weak_ptr<Foo>& p) {
  std::cout << "----------" << std::boolalpha
    << "\nexpired: " << p.expired()
    << "\nuse_count: " << p.use_count()
    << "\ncontent: ";

  // If we want to access the actual object, we need to call the lock function. It returns a shared pointer to the
  // object. In case the object does not exist any longer, the shared pointer we got from it is effectively a null
  // pointer. We need to check that, and then we can access it.
  if (const auto sp(p.lock()); sp) {
    std::cout << sp->value << '\n';
  } else {
    std::cout << "<null>\n";
  }
}

void weak_ptr() {
  // Instantiate an empty weak pointer
  std::weak_ptr<Foo> weak_foo;
  weak_ptr_info(weak_foo);

  {
    auto shared_foo(std::make_shared<Foo>(1337));
    weak_foo = shared_foo;
    weak_ptr_info(weak_foo);
  }

  weak_ptr_info(weak_foo);
}

#endif // C__17_STL_COOKBOOK_UTILITY_CLASSES_WEAK_PTR_H_
