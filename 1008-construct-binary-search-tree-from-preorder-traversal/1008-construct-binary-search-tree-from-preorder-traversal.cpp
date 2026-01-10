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
    TreeNode* bstFormation(vector<int>& preorder, int low, int high) {
        if (low > high)
            return nullptr;
        if (low == high)
            return new TreeNode(preorder[low]);
        TreeNode* root = new TreeNode(preorder[low]);
        int curr = low + 1;
        while (curr <= high && preorder[curr] < preorder[low])
            curr++;
        root->left = bstFormation(preorder, low + 1, curr - 1);
        root->right = bstFormation(preorder, curr, high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFormation(preorder, 0, preorder.size() - 1);
    }
};