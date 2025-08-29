class Solution {
public:
    long long flowerGame(int n, int m) {
        long long count = 0;
        count += 1ll * ((n + 1) / 2) * (m / 2);
        count += 1ll * ((m + 1) / 2) * (n / 2);
        return count;
    }
};