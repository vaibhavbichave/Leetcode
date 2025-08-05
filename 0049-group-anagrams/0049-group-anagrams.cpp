class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_map<string, vector<string>> mp;
        for (auto str : strs)
            mp[getKey(str)].push_back(str);
        for (auto x : mp)
            v.push_back(x.second);
        return v;
    }
    string getKey(string str) {
        string key;
        vector<int> count(26, 0);
        for (char x : str)
            count[x - 'a']++;
        for (int num : count)
            key += to_string(num) + "#";
        return key;
    }
};