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
        while (answer && answer->next && answer->next->next) {
            if (answer->next->val == answer->next->next->val) {
                answer->next = answer->next->next;
            } else {
                answer = answer->next;
            }
        }
        return result->next;
    }
};