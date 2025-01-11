class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        if (n < k) return false;
        if (n == k) return true;
        int setBits = 0;
        for (char chr : s) mp[chr]++;
        for (auto [chr, flag] : mp) setBits += flag & 1;
        return setBits <= k;
    }
};