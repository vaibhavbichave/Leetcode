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
    ListNode* reverseList(ListNode* head) {
        ListNode *next, *prev = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = getSize(l1), m = getSize(l2), carry = 0;
        if (n < m)
            return addTwoNumbers(l2, l1);
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* result = new ListNode(0, l1);
        ListNode* answer = result;
        for (int i = 0; i < n; i++) {
            result->next->val += carry;
            if (l2) {
                result->next->val += l2->val;
                l2 = l2->next;
            }
            carry = result->next->val / 10;
            result->next->val %= 10;
            result = result->next;
        }
        if (carry) {
            result->next = new ListNode(carry);
        }
        return reverseList(answer->next);
    }
};