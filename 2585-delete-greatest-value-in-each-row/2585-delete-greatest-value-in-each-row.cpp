class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), result = 0;
        for (int i = 0; i < n; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        for (int i = 0; i < m; i++) {
            int maxi = INT_MIN;
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, grid[j][i]);
            }
            result += maxi;
        }
        return result;
    }
};