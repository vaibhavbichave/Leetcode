/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void deleteNode(TreeNode*& root, vector<TreeNode*>& res,
                    unordered_set<int>& st) {
        if (root) {
            deleteNode(root->left, res, st);
            deleteNode(root->right, res, st);
            if (st.find(root->val) != st.end()) {
                if (root->left) {
                    res.push_back(root->left);
                }
                if (root->right) {
                    res.push_back(root->right);
                }
                root = NULL;
            }
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int n = to_delete.size();
        vector<TreeNode*> res;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(to_delete[i]);
        }
        deleteNode(root, res, st);
        if (root) {
            res.push_back(root);
        }
        return res;
    }
};