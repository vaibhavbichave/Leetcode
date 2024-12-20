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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool odd = true;
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> v;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                v.push_back(node);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            odd = !odd;
            if (odd)
                for (int i = 0; i < n; i += 2)
                    swap(v[i]->val, v[n - 1 - i]->val);
        }
        return root;
    }
};