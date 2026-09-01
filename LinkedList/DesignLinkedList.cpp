#include <iostream>
using namespace std;
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
class MyLinkedList {
 public:
  ListNode* head;
  MyLinkedList() { head = nullptr; }

  int get(int index) {
    if (head == nullptr or index < 0) {
      return -1;
    }

    // traverse upto that index
    ListNode* temp = head;
    for (int i = 0; i < index and temp != nullptr; i++) {
      temp = temp->next;
    }

    if (temp == nullptr) {
      return -1;  // invalid index
    }
    return temp->val;
  }

  void addAtHead(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    return;
  }

  void addAtTail(int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
      // empty LL
      head = newNode;
      return;
    }

    // traverse till tail
    ListNode* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    // you are tail node
    temp->next = newNode;
  }

  void addAtIndex(int index, int val) {
    ListNode* newNode = new ListNode(val);
    if (index < 0) {
      return;  // invalid index
    }

    if (index == 0) {
      newNode->next = head;
      head = newNode;
      return;
    }
    ListNode* temp = head;
    // traverse till index given -1 position
    for (int i = 0; i < index - 1 && temp != nullptr; i++) {
      temp = temp->next;
    }

    // either u are index-1 pos or index given was invalid(so u r at last
    // node)
    if (temp == nullptr) {
      return;
    }
    // you are index-1 pos
    newNode->next = temp->next;
    temp->next = newNode;
  }

  void deleteAtIndex(int index) {
    if (head == nullptr or index < 0) {
      return;
    }

    ListNode* temp = head;
    if (index == 0) {
      head = temp->next;
      delete temp;
      return;
    }
    // traverse till position -1
    for (int i = 0; i < index - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }

    if (temp->next == nullptr) {
      return;
    }

    // you are index -1 pos
    ListNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */