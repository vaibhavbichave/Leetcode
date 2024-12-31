class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxi = 0;
        unordered_set<int> st;
        for (int x : days) {
            st.insert(x);
            maxi = max(x, maxi);
        }
        vector<int> dp(maxi + 1, 0);
        for (int i = 1; i < maxi + 1; i++) {
            dp[i] = dp[i - 1];
            if (st.find(i) != st.end()) {
                dp[i] = costs[0] + dp[i - 1];
                dp[i] = min(dp[i], costs[1] + dp[max(0, i - 7)]);
                dp[i] = min(dp[i], costs[2] + dp[max(0, i - 30)]);
            }
        }
        return dp[maxi];
    }
};