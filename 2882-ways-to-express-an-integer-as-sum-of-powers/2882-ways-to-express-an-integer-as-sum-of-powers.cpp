class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; pow(i, x) <= n; ++i) 
            powers.push_back(pow(i, x));
        int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers)
            for (int s = n; s >= p; --s)
                dp[s] = (dp[s] + dp[s - p]) % MOD;
        return dp[n];
    }
};