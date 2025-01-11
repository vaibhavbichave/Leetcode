class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> v(26, 0), vv(26, 0);
        for (char chr : s1)
            v[chr - 'a']++;
        for (int i = 0; i < min(n, m); i++)
            vv[s2[i] - 'a']++;
        for (int i = n; i < m; i++) {
            if (v == vv) return true;
            vv[s2[i] - 'a']++;
            vv[s2[i - n] - 'a']--;
        }
        return v == vv;
    }
};