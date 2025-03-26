class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int n = grid.size(), m = grid[0].size();
        int rem = grid[0][0] % x, total = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] % x != rem) {
                    return -1;
                }
                total += grid[i][j];
                v.push_back(grid[i][j]);
            }
        }
        int result = INT_MAX;
        sort(v.begin(), v.end());
        for (int i = 0; i < m * n; i++) {
            result = min(result, (v[i] * i - sum) / x +
                                     (total - sum - v[i] * (n * m - i)) / x);
            sum += v[i];
        }
        return result;
    }
};