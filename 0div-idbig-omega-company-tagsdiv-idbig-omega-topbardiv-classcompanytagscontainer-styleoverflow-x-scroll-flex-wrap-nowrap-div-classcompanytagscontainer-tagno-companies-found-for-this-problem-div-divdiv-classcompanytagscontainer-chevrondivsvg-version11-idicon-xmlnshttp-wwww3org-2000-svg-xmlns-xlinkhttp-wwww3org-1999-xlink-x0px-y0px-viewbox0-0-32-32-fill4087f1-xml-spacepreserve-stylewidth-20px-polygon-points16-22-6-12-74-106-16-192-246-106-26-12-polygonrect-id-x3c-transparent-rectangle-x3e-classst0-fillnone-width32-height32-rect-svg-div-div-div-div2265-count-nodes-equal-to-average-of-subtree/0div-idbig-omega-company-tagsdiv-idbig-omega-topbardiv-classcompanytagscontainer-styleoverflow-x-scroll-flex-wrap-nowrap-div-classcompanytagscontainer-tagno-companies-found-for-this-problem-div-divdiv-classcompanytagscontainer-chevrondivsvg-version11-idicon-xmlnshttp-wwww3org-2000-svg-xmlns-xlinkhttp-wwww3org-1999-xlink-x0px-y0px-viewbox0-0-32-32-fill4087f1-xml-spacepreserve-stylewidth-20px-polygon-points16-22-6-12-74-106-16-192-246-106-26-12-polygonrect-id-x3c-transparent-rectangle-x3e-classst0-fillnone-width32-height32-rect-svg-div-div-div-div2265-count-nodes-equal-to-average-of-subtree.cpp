/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getValue(TreeNode *root){
        if(!root) return 0;
        return root->val;
    }
    int dfs(TreeNode *root,int &result){
        if(!root) return 0;
        int data = root->val;
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        int avg = (root->val+getValue(root->left)+getValue(root->right)) / (left+right+1);
        root->val = root->val+ getValue(root->left)+getValue(root->right);
        if(avg==data) result++;
        return left+right+1;
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0, result=0;
        dfs(root,result);
        return result;
    }
};