/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if (root) {
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                vector<int> vv;
                for (int i = q.size(); i > 0; i--) {
                    Node* node = q.front();
                    q.pop();
                    vv.push_back(node->val);
                    for (Node* child : node->children)
                        q.push(child);
                }
                v.push_back(vv);
            }
        }
        return v;
    }
};