class Solution {
public:
    double myPow(double x, int n) {
        long binary = n;
        if (n < 0) {
            x = 1 / x;
            binary = -binary;
        }
        double ans = 1.0;
        while (binary > 0) {
            if (binary & 1)
                ans *= x;
            x *= x;
            binary /= 2;
        }
        return ans;
    }
};