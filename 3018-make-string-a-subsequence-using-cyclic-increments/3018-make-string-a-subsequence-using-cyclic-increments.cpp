class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int n = str1.size(), m = str2.size();
        while (i < n && j < m) {
            char next = 'a' + ((str1[i] - 'a') + 1) % 26;
            if (str1[i] == str2[j] || next == str2[j]) {
                j++;
            }
            i++;
        }
        return j == m;
    }
};