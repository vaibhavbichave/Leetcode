class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> v;
        int n = land.size(), m = land[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j]) {
                    int x = i, y = j;
                    while (x < n && land[x][j])
                        x++;
                    while (y < m && land[i][y])
                        y++;
                    for (int r = i; r < x; r++)
                        for (int c = j; c < y; c++)
                            land[r][c] = 0;
                    v.push_back({i, j, x - 1, y - 1});
                }
            }
        }
        return v;
    }
};