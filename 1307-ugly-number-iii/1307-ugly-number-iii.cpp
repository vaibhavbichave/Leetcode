class Solution {
public:
    long long lcm(long long a, long long b) { return a * b / __gcd(a, b); }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ca = lcm(c, a);
        long long abc = lcm(ab, c);
        long long low = 1, high = 2e9;
        while (low < high) {
            long long x = low + (high - low) / 2;
            long long before =
                x / a + x / b + x / c - x / ab - x / bc - x / ca + x / abc;
            if (before >= n) {
                high = x;
            } else {
                low = x + 1;
            }
        }
        return high;
    }
};