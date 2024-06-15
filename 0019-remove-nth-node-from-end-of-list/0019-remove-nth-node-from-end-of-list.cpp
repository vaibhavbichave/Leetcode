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
    int getLength(ListNode* node) {
        int length = 0;
        ListNode* head = node;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = getLength(head);
        ListNode* temp = new ListNode(0, head);
        ListNode* result = temp;
        for (int idx = 0; idx < sz - n; idx++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return result->next;
    }
};