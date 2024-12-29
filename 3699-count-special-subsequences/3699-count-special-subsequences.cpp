class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        unordered_map<double, int> cnt;
        for (int r = 4; r < n - 2; ++r) {
            for (int p = 0, q = r - 2; p <= q - 2; ++p)
                cnt[1.0 * nums[p] / nums[q]]++;
            for (int s = r + 2; s < n; ++s)
                res += cnt[1.0 * nums[s] / nums[r]];
        }
        return res;
    }
};