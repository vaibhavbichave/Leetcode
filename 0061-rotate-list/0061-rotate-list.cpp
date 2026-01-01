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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int length = 0;
        for (ListNode* temp = head; temp; temp = temp->next, length++);
        k %= length;
        if (k > 0) {
            k = length - k;
            ListNode* temp = new ListNode(0, head);
            while (k--) temp = temp->next;
            ListNode* next = temp->next;
            ListNode* result = next;
            temp->next = nullptr;
            while (next->next)
                next = next->next;
            next->next = head;
            return result;
        }
        return head;
    }
};