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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_set<int> st;
        unordered_map<int, TreeNode*> mp;
        for (int i = 0; i < n; i++) {
            int x = descriptions[i][0], y = descriptions[i][1];
            if (mp.find(x) == mp.end()) {
                TreeNode* parent = new TreeNode(x);
                mp[x] = parent;
            }
            if (mp.find(y) == mp.end()) {
                TreeNode* child = new TreeNode(y);
                mp[y] = child;
            }
            if (descriptions[i][2] == 1) {
                mp[x]->left = mp[y];
            } else {
                mp[x]->right = mp[y];
            }
            st.insert(y);
        }

        int root = 0;
        for (auto x : descriptions) {
            if (st.find(x[0]) == st.end()) {
                root = x[0];
            }
        }
        return mp[root];
    }
};