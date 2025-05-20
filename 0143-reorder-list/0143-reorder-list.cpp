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
    void reorderList(ListNode* head) {
        if (head && head->next && head->next->next) {
            ListNode *slow = head, *fast = head;
            while (fast && fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* last = reverse(slow->next);
            slow->next = nullptr;
            ListNode *first = head, *curr = head;
            while (first && last) {
                ListNode* firstNext = first->next;
                ListNode* lastNext = last->next;
                first->next = last;
                last->next = firstNext;
                last = lastNext;
                first = firstNext;
            }
        }
    }
};