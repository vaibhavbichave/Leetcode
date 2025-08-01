class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> v;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> vv(i + 1, 1);
            for (int j = 1; j < v.size(); j++) {
                vv[j] = v[j] + v[j - 1];
            }
            v = vv;
            ans.push_back(v);
        }
        return ans;
    }
};