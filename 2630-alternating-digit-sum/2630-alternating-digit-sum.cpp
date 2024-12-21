class Solution {
public:
    int alternateDigitSum(int n) {
        int res1 = 0, res2 = 0;
        int count = 0, odd = 0, even = 0;
        while (n) {
            int digit = n % 10;
            if (count & 1) {
                res1 += digit;
                res2 -= digit;
            } else {
                res1 -= digit;
                res2 += digit;
            }
            n /= 10;
            count++;
        }
        return count & 1 ? res2 : res1;
    }
};