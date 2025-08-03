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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        using pp = pair<int, ListNode*>;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (ListNode* list : lists)
            if (list)
                pq.push({list->val, list});
        while (!pq.empty()) {
            ListNode* node = pq.top().second;
            pq.pop();
            ListNode* next = node->next;
            if (next) {
                pq.push({next->val, next});
            }
            dummy->next = node;
            dummy = dummy->next;
            dummy->next = nullptr;
        }
        return ans->next;
    }
};