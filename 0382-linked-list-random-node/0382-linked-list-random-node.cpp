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
private:
    int length;
    unordered_map<int, int> mp;

public:
    Solution(ListNode* head) {
        ListNode* temp = head;
        for (length = 0; temp; length++) {
            mp[length] = temp->val;
            temp = temp->next;
        }
    }

    int getRandom() { return mp[rand() % length]; }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */