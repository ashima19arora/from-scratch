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
  ListNode* middleNode(ListNode* head) {
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    // find the length of the LL
    int count = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }

    // traverse till there
    temp = head;
    int midpoint = (count / 2) + 1;
    for (int i = 1; i < midpoint; i++) {
      temp = temp->next;
    }
    return temp;
  }
};