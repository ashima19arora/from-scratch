/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
 public:
  ListNode* removeElements(ListNode*& head, int data) {
    // linked is empty case
    if (head == nullptr) {
      return head;
    }

    // val is present at first node -delete head
    while (head != nullptr && head->val == data) {
      ListNode* toDelete = head;
      head = head->next;
      delete toDelete;
    }
    // u r here because either ll is now empty or the val at head does not
    // match data
    if (head == nullptr) {
      return head;
    }
    ListNode* temp = head;
    // now traversing the entire linked list
    // we will traverse till second last node
    while (temp->next != nullptr) {
      // we will stop at one postion before the val occurs
      if (temp->next->val == data) {
        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
      } else {
        temp = temp->next;
      }
    }
    return head;
  }
};