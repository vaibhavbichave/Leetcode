class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = 0, power = 0;
        long long val = 0, n = s.size();
        for (int i = n - 1; i >= 0; i--, power++) {
            if (s[i] == '1' && power < 32 && (val + (1ll << power)) <= k) {
                val += (1LL << power);
                cnt++;
            }
            cnt += (s[i] == '0');
        }
        return cnt;
    }
};