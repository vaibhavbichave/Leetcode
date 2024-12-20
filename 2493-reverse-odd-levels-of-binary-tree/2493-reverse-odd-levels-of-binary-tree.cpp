class Solution {
private:
    void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (leftChild && rightChild) {
            if (level & 1) swap(leftChild->val, rightChild->val);
            traverseDFS(leftChild->left, rightChild->right, level + 1);
            traverseDFS(leftChild->right, rightChild->left, level + 1);
        }
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverseDFS(root->left, root->right, 1);
        return root;
    }
};