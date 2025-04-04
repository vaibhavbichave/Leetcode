class Solution {
public:
    pair<int, TreeNode*> helper(TreeNode* node) {
        if (!node) return {0, nullptr};
        auto left = helper(node->left);
        auto right = helper(node->right);
        if (left.first > right.first)
            return {left.first + 1, left.second};
        else if (left.first < right.first)
            return {right.first + 1, right.second};
        return {left.first + 1, node};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).second;
    }
};