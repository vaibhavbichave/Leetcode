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
        ListNode* answer = new ListNode(0, head);
        ListNode* result = answer;
        while (answer->next && answer->next->next) {
            ListNode* node1 = answer->next;
            ListNode* node2 = answer->next->next;
            node1->next = node2->next;
            node2->next = node1;
            answer->next = node2;
            answer = answer->next->next;
        }
        return result->next;
    }
};