class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondRowSum = 0, minimumSum = LLONG_MAX;
        for (int index = 0; index < grid[0].size(); ++index) {
            firstRowSum -= grid[0][index];
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][index];
        }
        return minimumSum;
    }
};