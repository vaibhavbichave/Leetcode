class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> diagonal;
            for (int x = i, y = 0; x < n && y < n; x++, y++)
                diagonal.push_back(grid[x][y]);
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            for (int x = i, y = 0; x < n && y < n; x++, y++)
                grid[x][y] = diagonal[y];
        }
        for (int i = 1; i < n; i++) {
            vector<int> diagonal;
            for (int x = 0, y = i; x < n && y < n; x++, y++)
                diagonal.push_back(grid[x][y]);
            sort(diagonal.begin(), diagonal.end());
            for (int x = 0, y = i; x < n && y < n; x++, y++)
                grid[x][y] = diagonal[x];
        }
        return grid;
    }
};