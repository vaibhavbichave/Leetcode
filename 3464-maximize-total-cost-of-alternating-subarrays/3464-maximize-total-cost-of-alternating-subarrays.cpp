class Solution {
public:
    long long maximumTotalCost(vector<int>& a) {
        long long n = a.size();
        vector<vector<long long>>dp(n, vector<long long>(2,-1LL<<61));
        dp[0][0] = a[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i][0], max(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]));
            dp[i][1] = max(dp[i][1], dp[i - 1][0] - a[i]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};