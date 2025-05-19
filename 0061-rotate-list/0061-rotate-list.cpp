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
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n = getSize(head);
        if (n == 0 || k % n == 0)
            return head;
        for (int i = 1; i < n - k % n; i++) {
            head = head->next;
        }
        ListNode * result = head->next;
        ListNode* answer = result;
        head->next = nullptr;
        while (result->next)
            result = result->next;
        result->next = temp;
        return answer;
    }
};