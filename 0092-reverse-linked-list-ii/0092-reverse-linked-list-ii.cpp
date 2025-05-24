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
    ListNode* reverse(ListNode* curr, ListNode* prev) {
        ListNode *last = prev, *next;
        while (curr != last) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* answer = new ListNode(0, head);
        ListNode* result = answer;
        for (int i = 1; i < left; i++) {
            answer = answer->next;
        }
        ListNode *first = answer, *last;
        for (int i = left; i <= right; i++) {
            answer = answer->next;
            last = answer;
        }
        first->next = reverse(first->next, last->next);
        return result->next;
    }
};