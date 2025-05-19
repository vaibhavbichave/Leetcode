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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *initA = headA, *initB = headB;
        while (headA && headB) {
            if (headA == headB)
                return headA;
            if (!headA->next && !headB->next)
                break;
            headA = headA->next ? headA->next : initB;
            headB = headB->next ? headB->next : initA;
        }
        return nullptr;
    }
};