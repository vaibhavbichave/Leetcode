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
        ListNode* temp = new ListNode(0);
        ListNode* result = temp;
        using pp = pair<int, ListNode*>;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (auto node : lists) {
            if (node)
                pq.push({node->val, node});
        }
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            temp->next = node;
            temp = temp->next;
            if (node->next)
                pq.push({node->next->val, node->next});
        }
        return result->next;
    }
};