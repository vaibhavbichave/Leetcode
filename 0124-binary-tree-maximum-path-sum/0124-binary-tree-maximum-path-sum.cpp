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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
    int dfs(TreeNode* root, int& maxi) {
        if (!root) return 0;
        int left = max(dfs(root->left, maxi), 0);
        int right = max(dfs(root->right, maxi), 0);
        maxi = max(maxi, root->val + left + right);
        return root->val + max(left, right);
    }
};