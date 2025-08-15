class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> v;
        unordered_map<string, int> mp;
        for (int i = 0; i <= n - 10; i++)
            mp[s.substr(i, 10)]++;
        for (auto [substr, count] : mp)
            if (count > 1)
                v.push_back(substr);
        return v;
    }
};