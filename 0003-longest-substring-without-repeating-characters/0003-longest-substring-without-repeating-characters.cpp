class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), count = 0;
        unordered_map<char, int> mp;
        for (int i = 0, j = 0; j < n; j++) {
            mp[s[j]]++;
            while (mp[s[j]] > 1)
                mp[s[i++]]--;
            count = max(count, j - i + 1);
        }
        return count;
    }
};