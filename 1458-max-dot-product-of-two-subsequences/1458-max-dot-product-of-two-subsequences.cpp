class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), maxi = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int product = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], max(0, dp[i - 1][j - 1]) + product);
            }
        }
        return dp[n][m];
    }
};