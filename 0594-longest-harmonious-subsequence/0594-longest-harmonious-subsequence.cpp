class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxi = 0;
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        for (auto [num, count] : mp) {
            if (mp.find(num + 1) != mp.end()) {
                maxi = max(maxi, count + mp[num + 1]);
            }
        }
        return maxi;
    }
};