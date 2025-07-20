class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        for (auto point : points)
            mp[point[1]]++;
        long long sum = 0;
        for (auto [_, count] : mp)
            sum += 1ll * count * (count - 1) / 2;
        long long ans = 0, rem = sum;
        for (auto [_, count] : mp) {
            long long curr = 1ll * count * (count - 1) / 2;
            rem -= curr;
            ans = (ans + (rem * curr) % MOD) % MOD;
        }
        return ans;
    }
};