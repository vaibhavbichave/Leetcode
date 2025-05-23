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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefix = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        dummy->next = head;
        unordered_map<int, ListNode*> mp;
        while (current) {
            prefix += current->val;
            if (mp.find(prefix) == mp.end()) {
                mp[prefix] = current;
            } else {
                current = mp[prefix]->next;
                int sum = prefix + current->val;
                while (sum != prefix) {
                    mp.erase(sum);
                    current = current->next;
                    sum += current->val;
                }
                mp[prefix]->next = current->next;
            }
            current = current->next;
        }
        return dummy->next;
    }
};