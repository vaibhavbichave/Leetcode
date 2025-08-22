class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int rlow = n, rhigh = -1, clow = m, chigh = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    rlow = min(rlow, i), rhigh = max(rhigh, i),
                    clow = min(clow, j), chigh = max(chigh, j);
        return (rhigh - rlow + 1) * (chigh - clow + 1);
    }
};