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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        while(temp) temp = temp->next, count++;
        if(count == 1) return head->next;
        count = count / 2;
        temp = head;
        for(int i=1;i<count;i++) temp = temp->next;
        temp->next = temp->next->next;
        return head;
    }
};