#ifndef C__17_STL_COOKBOOK_UTILITY_CLASSES_LEGACY_APIS_WITH_SMART_POINTERS_H_
#define C__17_STL_COOKBOOK_UTILITY_CLASSES_LEGACY_APIS_WITH_SMART_POINTERS_H_

#include <iostream>
#include <memory>
#include <string>

class Foo {
 public:
  static Foo* CreateFoo(std::string s) {
    return new Foo { std::move(s) };
  }

  static void DestroyFoo(Foo* p) {
    delete p;
  }

 private:
  std::string name_;

  explicit Foo(std::string name) : name_(std::move(name)) {
    std::cout << "CTOR " << name_ << '\n';
  }

  ~Foo() {
    std::cout << "DTOR " << name_ << '\n';
  }

}; // class Foo

// Make such object manageable by shared_ptr
static std::shared_ptr<Foo> make_shared_foo(std::string s) {
  return { Foo::CreateFoo(std::move(s)), Foo::DestroyFoo };
}

// This trick with a custom deleter is infeasible for unique_ptr, because unique_ptr does not rely on virtual functions.
// Here, we need to change the type of the unique_ptr. As a second template parameter, we give it void (*)(Foo*), which
// is exactly the type of pointer to the function, DestroyFoo.
static std::unique_ptr<Foo, void (*)(Foo*)> make_unique_foo(std::string s) {
  return { Foo::CreateFoo(std::move(s)), Foo::DestroyFoo };
}

void legacy_apis_with_smart_pointers() {
  auto ps(make_shared_foo("shared Foo instance"));
  auto pu(make_unique_foo("unique Foo instance"));
}

#endif // C__17_STL_COOKBOOK_UTILITY_CLASSES_LEGACY_APIS_WITH_SMART_POINTERS_H_
