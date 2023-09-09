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
    void sortedInsert(ListNode *sorted, ListNode *newnode){
        if (sorted->val >= newnode->val) {
            newnode->next = sorted;
            sorted = newnode;
        }
        else {
            ListNode* current = sorted;
            while (current->next && current->next->val < newnode->val) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sorted = new ListNode(INT_MIN);
        ListNode *current = head;
        while (current) {
            ListNode* next = current->next;
            sortedInsert(sorted,current);
            current = next;
        }
        return sorted->next;
    }
};