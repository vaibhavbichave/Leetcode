class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long share = 0, MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (forget <= i)
                share = (share - dp[i - forget] + MOD) % MOD;
            if (delay <= i)
                share = (share + dp[i - delay]) % MOD;
            dp[i] = share;
        }
        long long know = 0;
        for (int i = 0; i < forget; i++)
            know = (know + dp[n - i]) % MOD;
        return know;
    }
};