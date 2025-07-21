class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 0, prev = 0;
        string ans;
        for (char x : s) {
            if (prev == x) {
                if (cnt == 1) {
                    continue;
                }
                cnt++;
            } else {
                cnt = 0;
            }
            ans += x;
            prev = x;
        }
        return ans;
    }
};