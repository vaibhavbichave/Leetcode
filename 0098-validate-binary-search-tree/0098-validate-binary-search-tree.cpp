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
    int pre=INT_MIN,cnt=0;
    bool status=true;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        inorder(root);
        return status;
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(cnt!=0)
            status= status && !(pre>=root->val);
        pre=root->val;cnt++;
        inorder(root->right);    
    }
};