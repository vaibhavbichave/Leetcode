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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v(k, nullptr);
        int len=0;
        for(auto i=head;i;i=i->next)
            len++;
         int n = len / k, r = len % k;
        ListNode* node=head,*prev=NULL;
        for(int i=0;node && i<k; i++){
            int extra=r>0?1:0;r--;
            v[i]=node;
            for(int j=0;j<n+extra;j++){
                prev= node;
                node=node->next;
            }
            prev->next= NULL;
        }
        return v;
    }
};