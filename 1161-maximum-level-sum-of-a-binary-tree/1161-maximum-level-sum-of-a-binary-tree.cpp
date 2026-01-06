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
    int maxLevelSum(TreeNode* root) {
        int res = 0, ans = 0, maxi = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sum = 0;
            res++;
            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans = sum > maxi ? res : ans;
            maxi = max(maxi, sum);
        }
        return ans;
    }
};