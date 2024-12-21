class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, sign = 1;
        while (n) {
            sign = -sign;
            res += sign * n % 10;
            n /= 10;
        }
        return sign * res;
    }
};