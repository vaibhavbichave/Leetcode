class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int row,
             int col) {
        if (!ocean[row][col]) {
            ocean[row][col] = true;
            int curr = heights[row][col];
            int n = heights.size(), m = heights[0].size();
            if (row + 1 < n && heights[row + 1][col] >= curr)
                dfs(heights, ocean, row + 1, col);
            if (row - 1 >= 0 && heights[row - 1][col] >= curr)
                dfs(heights, ocean, row - 1, col);
            if (col + 1 < m && heights[row][col + 1] >= curr)
                dfs(heights, ocean, row, col + 1);
            if (col - 1 >= 0 && heights[row][col - 1] >= curr)
                dfs(heights, ocean, row, col - 1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> v;
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n - 1, i);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (pacific[i][j] && atlantic[i][j])
                    v.push_back({i, j});
        return v;
    }
};