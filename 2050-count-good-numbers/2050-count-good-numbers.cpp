class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        auto quickmul = [&](int x, long long y) {
            int ret = 1, mul = x;
            while (y > 0) {
                ret = (y & 1) ? 1ll * ret * mul % mod : ret;
                mul = 1ll * mul * mul % mod;
                y >>= 1;
            }
            return ret;
        };
        return 1ll * quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};