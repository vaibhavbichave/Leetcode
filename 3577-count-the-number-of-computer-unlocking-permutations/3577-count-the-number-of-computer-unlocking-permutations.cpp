class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for (int i = 1; i < n; i++)
            if (complexity[i] <= complexity[0])
                return 0;
        long long result = 1, MOD = 1e9 + 7;
        for (int i = 2; i < n; i++)
            result = (result * i) % MOD;
        return result;
    }
};