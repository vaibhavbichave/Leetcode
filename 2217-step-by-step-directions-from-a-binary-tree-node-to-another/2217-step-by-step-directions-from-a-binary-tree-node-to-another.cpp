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
    TreeNode* LCA(TreeNode* root, int x, int y) {
        if (!root || root->val == x || root->val == y) return root;
        TreeNode* l = LCA(root->left, x, y);
        TreeNode* r = LCA(root->right, x, y);
        if (!l) return r;
        if (!r) return l;
        return root;
    }

    bool dfs(TreeNode* root, int x, string& path, bool dir) {
        if (root) {
            if (root->val == x) return 1;

            path += (dir ? 'U' : 'L');
            if (dfs(root->left, x, path, dir)) return 1;
            path.pop_back();

            path += (dir ? 'U' : 'R');
            if (dfs(root->right, x, path, dir)) return 1;
            path.pop_back();
        }
        return 0;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = LCA(root, startValue, destValue);
        string pathFrom, pathTo;
        dfs(root, startValue, pathFrom, 1);
        dfs(root, destValue, pathTo, 0);
        return pathFrom + pathTo;
    }
};
