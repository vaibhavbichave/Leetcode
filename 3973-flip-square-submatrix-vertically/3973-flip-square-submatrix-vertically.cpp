class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int n = grid.size(), m = grid[0].size();
        int top = x, bottom = x + k - 1;
        while (top < bottom) {
            for (int i = y; i < y + k; i++) {
                swap(grid[top][i], grid[bottom][i]);
            }
            top++, bottom--;
        }
        return grid;
    }
};