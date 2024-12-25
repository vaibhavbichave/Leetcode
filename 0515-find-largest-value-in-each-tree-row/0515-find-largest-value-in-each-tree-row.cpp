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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int maxi = INT_MIN;
                for (int i = q.size(); i > 0; i--) {
                    TreeNode* node = q.front();
                    maxi = max(maxi, node->val);
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                v.push_back(maxi);
            }
        }
        return v;
    }
};