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
    int minDiffInBST(TreeNode* root) {
        int prev = -1e9, res = INT_MAX;
        std::function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (node) {
                inorder(node->left);
                res = std::min(res, node->val - prev);
                prev = node->val;
                inorder(node->right);
            }
        };
        inorder(root);
        return res;
    }
};
