#include <iostream>
using namespace std;

#include "ListNode.h"  //same folder
// Section 01- insertion,printing ,deletion
//  we are going to use list node in this IAH function , so this function also
//  must be templatized
template <typename T>
// pass head by REFERENCE
void insertAtHead(ListNode<T>*& head, int data) {
  ListNode<int>* newNode = new ListNode<int>(data);
  // newNode stores address of newly inserted node
  //*newNode is actually the new Node(val + address)
  (*newNode).next = head;
  head = newNode;
}
template <typename T>
void printLL(ListNode<T>*& head) {
  ListNode<int>* temp = head;
  while (temp != nullptr) {
    cout << temp->val << "-->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

// searching iteratively
template <typename T>
bool searchInLL(ListNode<T>*& head, T key) {
  ListNode<int>* temp = head;
  while (temp != nullptr) {
    if (temp->val == key) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

// searching recursively
template <typename T>
bool searchInLLRecursively(ListNode<T>* start, T key) {
  if (start == nullptr) {
    return false;
  }
  // current state f(i,key)
  if (start == nullptr) {
    return true;
  }
  start = start->next;
  return searchInLLRecursively(start, key);
}

template <typename T>
void insertAtTail(ListNode<T>*& head, T data) {
  ListNode<T>* newNode = new ListNode<T>(data);
  // check if list is empty - then this is first node
  if (head == nullptr) {
    head = newNode;
    return;
  }
  // else traverse till tail
  ListNode<T>* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newNode;
  return;
}
