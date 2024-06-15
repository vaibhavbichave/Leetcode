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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                minheap.push({lists[i]->val, i});
            }
        }
        ListNode* node = new ListNode(0);
        ListNode* head = node;
        while (!minheap.empty()) {
            auto top = minheap.top();
            minheap.pop();
            node->next = new ListNode(top.first);
            node = node->next;
            if (lists[top.second]->next) {
                lists[top.second] = lists[top.second]->next;
                minheap.push({lists[top.second]->val, top.second});
            }
        }
        return head->next;
    }
};