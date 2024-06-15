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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* result = head;
        if (head && head->next) {
            int n = getLength(head);
            k = (n - k % n) % n;
            if (k > 0) {
                ListNode* node = head;
                for (int i = 0; i < k - 1; i++) {
                    node = node->next;
                }
                result = node->next;
                node->next = nullptr;
                node = result;
                while (node->next) {
                    node = node->next;
                }
                node->next = head;
            }
        }
        return result;
    }
};