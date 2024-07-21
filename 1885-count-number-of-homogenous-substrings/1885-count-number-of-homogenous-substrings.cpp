class Solution {
public:
    int countHomogenous(string s) {
        long long i = 0, result = 0, n = s.size(), mod = 1e9 + 7;
        while (i < n) {
            char x = s[i];
            long long count = 0;
            while (i < n && s[i] == x) {
                i++, count++;
            }
            result = (result + (count * (count + 1) / 2) % mod) % mod;
        }
        return result;
    }
};