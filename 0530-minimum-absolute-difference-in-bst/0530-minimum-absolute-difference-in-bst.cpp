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
public:
    int getMinimumDifference(TreeNode* root) {
        int prev = -1e9, res = INT_MAX;
        inorder(root, prev, res);
        return res;
    }
    void inorder(TreeNode* root, int& prev, int& res) {
        if (root) {
            inorder(root->left, prev, res);
            res = min(res, root->val - prev);
            prev = root->val;
            inorder(root->right, prev, res);
        }
    }
};