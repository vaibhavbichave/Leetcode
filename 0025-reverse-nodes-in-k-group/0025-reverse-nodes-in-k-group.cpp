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
    ListNode* reverse(ListNode* head, ListNode* last) {
        ListNode *curr = head, *next, *prev = last;
        while (curr != last) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* node = dummy;
        while (node) {
            ListNode* last = node;
            int i = 0;
            while (i < k && last->next) {
                i++, last = last->next;
            }
            if (i == k) {
                ListNode* next = node->next;
                node->next = reverse(node->next, last->next);
                node = next;
            } else {
                break;
            }
        }
        return dummy->next;
    }
};