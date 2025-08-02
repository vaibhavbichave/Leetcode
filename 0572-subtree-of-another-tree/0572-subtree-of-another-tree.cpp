class Solution {
private:
    string serialize(TreeNode* node) {
        if (node)
            return "(" + to_string(node->val) + "," + serialize(node->left) +
                   "," + serialize(node->right) + ")";
        return "null";
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return serialize(root).contains(serialize(subRoot));
    }
};