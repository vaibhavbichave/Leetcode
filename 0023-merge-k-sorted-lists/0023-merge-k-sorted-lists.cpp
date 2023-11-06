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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                minheap.push({lists[i]->val,i});
            }
        }
        ListNode* node=new ListNode(0);
        ListNode* head=node;
        while(!minheap.empty()){
            node->next=new ListNode();
            node=node->next;  
            pair<int,int>x=minheap.top();
            minheap.pop();
            node->val=x.first;
            if(lists[x.second]->next!=NULL){
                lists[x.second]=lists[x.second]->next;
                minheap.push({lists[x.second]->val,x.second});
            }
        }
        return head->next;
    }
};