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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        if (getLength(l1) < getLength(l2)) {
            head->next = l2;
        } else {
            head->next = l1;
        }
        while (l1 || l2) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            head->next->val = carry % 10;
            head = head->next;
            carry /= 10;
        }
        if (carry) {
            head->next = new ListNode(carry);
        }
        return result->next;
    }
};