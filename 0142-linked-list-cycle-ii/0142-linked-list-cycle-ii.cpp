/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* cycle(ListNode* node) {
        ListNode *slow = node, *fast = node;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return slow;
        }
        return nullptr;
    }
    ListNode* detectCycle(ListNode* head) {
        ListNode *p1 = cycle(head), *p2 = head;
        if (p1) {
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return p1;
    }
};