class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> v, mp(26, 0), freq(26, 0);
        for (auto x : p)
            mp[x - 'a']++;
        for (int i = 0; i < n; i++) {
            if (i >= m) freq[s[i - m] - 'a']--;
            freq[s[i] - 'a']++;
            if (freq == mp) v.push_back(i - m + 1);
        }
        return v;
    }
};