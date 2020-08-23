#ifndef C__17_STL_COOKBOOK_UTILITY_CLASSES_SHARED_PTR_H_
#define C__17_STL_COOKBOOK_UTILITY_CLASSES_SHARED_PTR_H_

/**
 * The shared_ptr pointer type was designed specifically for the case of multiple object owning the same dynamically
 * allocated object. In this case it would be unclear who has to delete it later. Shared pointers can be copied
 * arbitrarily often. An internal reference counting mechanism tracks how many objects are still maintaining a pointer
 * to the payload object. Only the last shared pointer that goes out of scope will call delete on the payload object.
 * This way we can be sure that we do not get memory leaks because objects are deleted automatically after use. At the
 * same time, we can be sure that they are not deleted too early, or too often (every created object must only be
 * deleted once).
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

void f(std::shared_ptr<Foo> sp) { // NOLINT
  std::cout << "f: use counter at " << sp.use_count() << '\n';
}

void shared_ptr() {
  std::shared_ptr<Foo> fa;

  {
    std::cout << "Inner scope begin\n";
    std::shared_ptr<Foo> f1 { new Foo { "foo" } };
    auto f2(std::make_shared<Foo>("bar"));
    std::cout << "f1's use counter at " << f1.use_count() << '\n';
    fa = f1;
    std::cout << "f1's use counter at " << f1.use_count() << '\n';
  }

  std::cout << "Back to outer scope\n";
  std::cout << fa.use_count() << '\n';

  std::cout << "first f() call\n";
  f(fa);
  std::cout << "second f() call\n";
  f(std::move(fa));

  std::cout << "end of main()\n";
}

#endif // C__17_STL_COOKBOOK_UTILITY_CLASSES_SHARED_PTR_H_
