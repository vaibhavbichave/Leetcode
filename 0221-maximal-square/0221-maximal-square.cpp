class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (i + 1 < n && j + 1 < m)
                        dp[i][j] = min(dp[i + 1][j + 1],
                                       min(dp[i][j + 1], dp[i + 1][j])) +
                                   1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi * maxi;
    }
};