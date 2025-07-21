class Solution {
public:
    string makeFancyString(string s) {
        int j = 2, i = 2, n = s.size();
        if (n >= 3) {
            while (i < n) {
                if (s[i] != s[j - 1] || s[i] != s[j - 2])
                    s[j++] = s[i];
                i++;
            }
            s.resize(j);
        }
        return s;
    }
};