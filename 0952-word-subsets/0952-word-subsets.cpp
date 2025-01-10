class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> v;
        unordered_map<char, int> mmp;
        for (string str : words2) {
            unordered_map<int, int> mp;
            for (char x : str) mp[x]++;
            for (auto [x, count] : mp) mmp[x] = max(mmp[x], count);
        }
        for (string str : words1) if (ispossible(mmp, str)) v.push_back(str);
        return v;
    }
    bool ispossible(unordered_map<char, int>& mmp, string& str) {
        unordered_map<char, int> mp;
        for (char x : str) mp[x]++;
        for (auto [x, count] : mmp) if (mp[x] < count) return false;
        return true;
    }
};