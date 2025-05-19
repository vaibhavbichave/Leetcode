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
    int getSize(ListNode* node) {
        int count = 0;
        ListNode* temp = node;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head) - n;
        ListNode* answer = new ListNode(0, head);
        ListNode* result = answer;
        for (int i = 0; i < size; i++) {
            result = result->next;
        }
        result->next = result->next->next;
        return answer->next;
    }
};