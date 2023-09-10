//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* merge(Node* first, Node* second){
        Node* result = new Node(0);
        Node* mergeNode = result;
        while(first && second){
            if(first->data<second->data){
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
    Node* middleNode(Node* head){
        Node *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        Node *head2 = new Node(0), *middle = new Node(0);
        middle = middleNode(head);
        head2 = middle->next;
        middle->next = NULL;
        return merge(mergeSort(head),mergeSort(head2));
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends