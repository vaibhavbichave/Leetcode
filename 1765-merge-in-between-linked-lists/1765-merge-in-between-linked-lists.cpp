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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 0;
        ListNode *slow = list1, *fast = list1;
        for (int i = 0; i <= b; i++) {
            slow = (i == a - 1) ? fast : slow;
            fast = fast->next;
        }
        slow->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = fast;
        return list1;
    }
};