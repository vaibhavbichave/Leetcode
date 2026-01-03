/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* curr = head;
        while (curr) {
            Node* dummy = new Node(curr->val);
            Node* next = curr->next;
            dummy->next = next;
            curr->next = dummy;
            curr = next;
        }
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        Node* result = head->next;
        curr = head;
        while (curr && curr->next) {
            Node* dummy = curr->next;
            Node* original = curr->next->next;
            if (original) dummy->next = original->next;
            curr->next = original;
            curr = curr->next;
        }
        return result;
    }
};