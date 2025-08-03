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
    bool isValidBST(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }
    bool helper(TreeNode* root, long leftMax, long rightMax) {
        if (!root) return true;
        if (leftMax < root->val && root->val < rightMax)
            return helper(root->left, leftMax, root->val) &&
                   helper(root->right, root->val, rightMax);
        return false;
    }
};