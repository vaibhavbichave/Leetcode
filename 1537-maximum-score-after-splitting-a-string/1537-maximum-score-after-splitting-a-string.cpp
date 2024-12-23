class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, res = 0, n = s.size();
        for (char x : s) if (x == '1') ones++;
        for (int i=0;i<n-1;i++) {
            char x = s[i];
            if (x == '0') zeros++;
            else ones--;
            res = max(res, zeros + ones);
        }
        return res;
    }
};