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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr = head, *node = head, *prev = nullptr;
        while (node) {
            while (node && node->val == 0) {
                node = node->next;
            }
            while (node && node->val != 0) {
                curr->val += node->val;
                node = node->next;
            }
            if (curr->val > 0) {
                prev = curr;
                curr = curr->next;
                curr->val = 0;
            }
        }
        prev->next = nullptr;
        return head;
    }
};