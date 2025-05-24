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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        vector<ListNode*> v(k, nullptr);
        for (ListNode* i = head; i; i = i->next) {
            len++;
        }
        int n = len / k, rem = len % k;
        ListNode* node = head;
        for (int i = 0; node && i < k; i++) {
            v[i] = node;
            ListNode* prev = nullptr;
            int extra = rem-- > 0 ? 1 : 0;
            for (int j = 0; j < n + extra; j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return v;
    }
};
