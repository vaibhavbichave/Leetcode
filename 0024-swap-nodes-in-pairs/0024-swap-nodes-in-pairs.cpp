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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0, head);
        ListNode* result = temp;
        while (temp->next && temp->next->next) {
            ListNode* first = temp->next;
            ListNode* second = temp->next->next;
            first->next = second->next;
            temp->next = second;
            second->next = first;
            temp = temp->next->next;
        }
        return result->next;
    }
};