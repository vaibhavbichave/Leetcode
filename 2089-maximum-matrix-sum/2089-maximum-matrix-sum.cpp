class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mini = INT_MAX, count = 0;
        for (auto& row : matrix) {
            for (int& x : row) {
                int absValue = abs(x);
                mini = min(mini, absValue);
                count += x < 0;
                sum += absValue;
            }
        }
        return (count & 1) ? sum - 2 * mini : sum;
    }
};