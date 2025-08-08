class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 2, result = n;
        for (int i = 2; i < n; i++) {
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};