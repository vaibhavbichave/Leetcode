class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bins;
        for (int i = 0; n; i++) {
            if (n & 1) bins.push_back(1 << i);
            n >>= 1;
        }
        vector<int> ans;
        for (const auto& query : queries) {
            long long curr = 1, MOD = 1e9 + 7;
            for (int i = query[0]; i <= query[1]; ++i)
                curr = (curr * bins[i]) % MOD;
            ans.push_back(curr);
        }
        return ans;
    }
};