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
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* result = new ListNode();
        ListNode* mergeNode = result;
        while(first && second){
            if(first->val<second->val){
                result->next = first;
                first = first->next;
                result = result->next;
            }
            else{
                result->next = second;
                second = second->next;
                result = result->next;
            }
        }
        while(first){
            result->next = first;
            first = first->next;
            result = result->next;
        }
        while(second){
            result->next = second;
            second = second->next;
            result = result->next;
        }
        return mergeNode->next;
    }
    ListNode* middleNode(ListNode* head){
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *head2 = new ListNode(), *middle = new ListNode();
        middle = middleNode(head);
        head2 = middle->next;
        middle->next = NULL;
        return merge(sortList(head),sortList(head2));
    }
};