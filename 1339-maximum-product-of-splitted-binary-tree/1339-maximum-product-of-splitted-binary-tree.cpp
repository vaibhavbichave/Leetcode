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
    long long dfs(TreeNode* root) {
        if (!root) return 0;
        return root->val += dfs(root->right) + dfs(root->left);
    }
    void edgedfs(TreeNode* root, long long total, long long& res) {
        if (root) {
            long long curr = root->val, MOD = 1e9 + 7;
            res = max(res, (total - curr) * curr);
            edgedfs(root->left, total, res);
            edgedfs(root->right, total, res);
        }
    }
    int maxProduct(TreeNode* root) {
        long long res = 0, total = dfs(root), MOD = 1e9 + 7;
        edgedfs(root, total, res);
        return res % MOD;
    }
};