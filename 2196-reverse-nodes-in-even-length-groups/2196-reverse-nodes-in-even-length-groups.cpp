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
    ListNode* reverse(int n, ListNode* curr, ListNode* prev) {
        ListNode* next;
        for (int i = 0; i < n && curr; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* answer = new ListNode(0, head);
        for (int j = 0, i = 1; answer; i++) {
            ListNode *first = answer, *last = nullptr;
            for (j = 0; j < i && answer->next; j++) {
                answer = answer->next;
                last = answer;
            }
            if (j % 2 == 0) {
                answer = first->next;
                if (last)
                    first->next = reverse(j, first->next, last->next);
                else
                    first->next = reverse(j, first->next, nullptr);
            }
        }
        return head;
    }
};