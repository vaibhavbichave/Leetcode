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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(-1);
        ListNode* p = result;
        while(carry || l1 || l2){
            int first = 0, second = 0, data = 0;
            if(l1){ 
                first = l1->val;
                l1 = l1->next;
            }
            if(l2){
                second = l2->val;
                l2 = l2->next;
            }
            data = (first+second+carry)%10;
            carry = (first+second+carry)/10;
            p->next = new ListNode(data);
            p = p->next;
        }
        return result->next;
    }
};