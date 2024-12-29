class Solution {
public:
    long long numberOfSubsequences(vector<int>& n) {
        long long res = 0, size = n.size();
        vector<vector<int>> cnt(1001, vector<int>(1001, 0));
        for (int q = n.size() - 5; q >= 2; q--) {
            for (int r = q + 2, s = q + 4; s < size; s++) {
                int f = gcd(n[r], n[s]);
                cnt[n[r] / f][n[s] / f]++;
            }
            for (int p = 0; p <= q - 2; p++) {
                int f = gcd(n[p], n[q]);
                res += cnt[n[q] / f][n[p] / f];
            }
        }
        return res;
    }
};