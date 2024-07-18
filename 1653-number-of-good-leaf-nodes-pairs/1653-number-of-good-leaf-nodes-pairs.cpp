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
private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        vector<int> result(distance + 1, 0);
        if (!node) {
        } else if (!node->left && !node->right) {
            result[1] = 1;
        } else {
            vector<int> left = dfs(node->left, distance, count);
            vector<int> right = dfs(node->right, distance, count);
            for (int i = 1; i <= distance; i++) {
                for (int j = 1; j <= distance - i; j++) {
                    count += left[i] * right[j];
                }
            }
            for (int i = 0; i < distance; i++) {
                result[i + 1] = left[i] + right[i];
            }
        }
        return result;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
};