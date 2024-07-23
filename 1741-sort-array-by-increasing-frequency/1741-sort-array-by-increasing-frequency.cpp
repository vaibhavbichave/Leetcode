class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        vector<pair<int, int>> v;
        for (auto x : mp) {
            v.push_back({x.second, x.first});
        }

        sort(v.begin(), v.end(), cmp);
        vector<int> result;
        for (auto x : v) {
            for (int i = 0; i < x.first; i++) {
                result.push_back(x.second);
            }
        }
        return result;
    }
};