class Solution {
public:
    bool isValid(unordered_map<char, int>& mp) {
        for (auto [_, count] : mp)
            if (count != 0)
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n)
            return false;
        unordered_map<char, int> mp;
        for (char x : s1)
            mp[x]++;
        for (int i = 0; i < m; i++) {
            mp[s2[i]]--;
            if (i - n >= 0)
                mp[s2[i - n]]++;
            if (isValid(mp))
                return true;
        }
        return false;
    }
};