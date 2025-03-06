class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = abs(grid[i][j]) - 1;
                if (grid[x / n][x % n] < 0) {
                    a = abs(grid[i][j]);
                }
                grid[x / n][x % n] = -abs(grid[x / n][x % n]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    b = i * n + j + 1;
                    break;
                }
            }
        }
        return {a, b};
    }
};