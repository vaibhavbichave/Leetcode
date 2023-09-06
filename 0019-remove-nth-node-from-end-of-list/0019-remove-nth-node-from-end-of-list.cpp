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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *p = new ListNode(-1);
        ListNode *q = p;
        p->next = head;
        while(q) q = q->next, count++;
        count = count - n;
        q = p;
        for(int i=1;i<count;i++) q = q->next;
        q->next = q->next->next;
        return p->next;
    }
};