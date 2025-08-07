class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        vector<int> v(k, 0);
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        vector<vector<int>> freq(n + 1);
        for (auto x : mp)
            freq[x.second].push_back(x.first);
        for (int i = n; i > 0; i--) {
            for (int num : freq[i]) {
                v[cnt++] = num;
                if (cnt == k)
                    return v;
            }
        }
        return v;
    }
};