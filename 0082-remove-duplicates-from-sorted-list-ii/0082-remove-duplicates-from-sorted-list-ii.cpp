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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* answer = new ListNode(0, head);
        ListNode* result = answer;
        while (answer->next && answer->next->next) {
            int curr = answer->next->val;
            if (curr != answer->next->next->val) {
                answer = answer->next;
            } else {
                while (answer->next && curr == answer->next->val) {
                    answer->next = answer->next->next;
                }
            }
        }
        return result->next;
    }
};