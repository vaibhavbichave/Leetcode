class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), len = 0, maxi = 0;
        unordered_map<char, int> mp;
        for (int r = 0, l = 0; r < n; r++) {
            mp[s[r]]++;
            maxi = max(maxi, mp[s[r]]);
            if (r - l + 1 - maxi > k) 
                mp[s[l++]]--;
            len = max(len, r - l + 1);
        }
        return len;
    }
};