class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int n = s.size(), m = spaces.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (j < m && spaces[j] == i) {
                res += ' ', j++;
            }
            res += s[i];
        }
        return res;
    }
};