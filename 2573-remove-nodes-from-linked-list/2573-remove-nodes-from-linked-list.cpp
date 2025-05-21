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
    ListNode* reverse(ListNode* node) {
        ListNode *prev = nullptr, *curr = node, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = reverse(head);
        ListNode* answer = new ListNode(0, temp);
        ListNode* result = answer;
        while (answer->next && answer->next->next) {
            if (answer->next->val > answer->next->next->val) {
                answer->next->next = answer->next->next->next;
            } else {
                answer = answer->next;
            }
        }
        return reverse(result->next);
    }
};