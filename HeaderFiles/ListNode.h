#include <iostream>

template <typename T>
class ListNode {
 public:
  T val;
  ListNode* next;  // self referential pointer

  // default constructor
  ListNode() { next = nullptr; }
  ListNode(T x) {
    val = x;
    next = nullptr;
  }
};