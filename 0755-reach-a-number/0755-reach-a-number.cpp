class Solution {
public:
    int reachNumber(int target) {
        target = target > 0 ? target : -target;
        long long n = target;
        long double root = std::sqrt(1.0L + 8.0L * n);
        long long k = static_cast<long long>(std::ceil((root - 1) / 2));
        long long next = k * (k + 1) / 2;
        long long diff = next - n;
        if ((diff & 1) == 0)
            return k;
        return k + 1 + (k & 1);
    }
};