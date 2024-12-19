class Solution {
public:
    int splitNum(int num) {
        string s;
        while (num) {
            int rem = num % 10;
            if (rem > 0) s += ('0' + rem);
            num /= 10;
        }
        int n = s.size(), sum1 = 0, sum2 = 0;
        sort(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            if (i & 1) sum1 = sum1 * 10 + (s[i] - '0');
            else sum2 = sum2 * 10 + (s[i] - '0');
        }
        return sum1 + sum2;
    }
};