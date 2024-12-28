class Solution {
public:
    int beautySum(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                int mini = INT_MAX, maxi = INT_MIN;
                for (auto [x, count] : mp) {
                    mini = min(mini, count);
                    maxi = max(maxi, count);
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};