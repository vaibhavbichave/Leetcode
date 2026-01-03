class Solution {
public:
    int numOfWays(int n) {
        long long MOD = 1e9 + 7;
        long long patternABA = 6;
        long long patternABC = 6;
        for (int i = 1; i < n; i++) {
            long long newPatternABA = (patternABA * 3 + patternABC * 2) % MOD;
            long long newPatternABC = (patternABA * 2 + patternABC * 2) % MOD;
            patternABA = newPatternABA;
            patternABC = newPatternABC;
        }
        return (patternABA + patternABC) % MOD;
    }
};