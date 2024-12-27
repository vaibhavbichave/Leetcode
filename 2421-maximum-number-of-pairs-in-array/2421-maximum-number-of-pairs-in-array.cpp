class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pair = 0, rem = 0;
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        for (auto x : mp) {
            pair += (x.second >> 1);
            rem += (x.second & 1);
        }
        return {pair, rem};
    }
};