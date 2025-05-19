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
        ListNode* answer = new ListNode();
        ListNode* result = answer;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;
        for (auto list : lists)
            if (list)
                pq.push({list->val, list});
        while (!pq.empty()) {
            auto [value, node] = pq.top();
            pq.pop();
            if (node->next)
                pq.push({node->next->val, node->next});
            answer->next = node;
            answer = answer->next;
        }
        return result->next;
    }
};