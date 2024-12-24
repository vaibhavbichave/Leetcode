class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        int m = spaces.size(), n = s.size();
        string t(n + m, ' ');
        for (int i = 0, j = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                j++;
            }
            t[i + j] = s[i];
        }
        return t;
    }
};