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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while (head) {
            while (!st.empty() && st.top()->val < head->val) {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }
        ListNode* result = nullptr;
        while (!st.empty()) {
            ListNode* top = st.top();
            top->next = result;
            result = top;
            st.pop();
        }
        return result;
    }
};