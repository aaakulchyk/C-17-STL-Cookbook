#ifndef C__17_STL_COOKBOOK_STL_CONTAINERS_PERSONAL_TODO_LIST_H_
#define C__17_STL_COOKBOOK_STL_CONTAINERS_PERSONAL_TODO_LIST_H_

#include <iostream>
#include <queue>
#include <string>
#include <tuple>

// Required to sort by priority
using item_t = std::pair<int, std::string>;

void personal_todo_list() {
  std::priority_queue<item_t> q;

  // In C++17 std::priority_queue has no constructor which accepts std::initializer_list
  std::initializer_list<item_t> il {
      { 1, "dishes" },
      { 0, "watch tv" },
      { 2, "do homework" },
      { 0, "read comics" },
  };

  // Iterate through unsorted list of to-do items and insert them
  for (const auto& p : il) {
    q.push(p);
  }

  // All items are implicitly sorted, and therefore we have a queue which gives us out items with the highest priority
  while (!q.empty()) {
    std::cout << q.top().first << ": " << q.top().second << '\n';
    q.pop();
  }

  std::cout << std::endl;
}

#endif // C__17_STL_COOKBOOK_STL_CONTAINERS_PERSONAL_TODO_LIST_H_
