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
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        ListNode* answer = new ListNode(0, reverse(head));
        ListNode* last = answer;
        while (answer->next) {
            answer->next->val <<= 1;
            answer->next->val += carry;
            carry = answer->next->val / 10;
            answer->next->val = answer->next->val % 10;
            answer = answer->next;
        }
        if (carry)
            answer->next = new ListNode(carry);
        return reverse(last->next);
    }
};