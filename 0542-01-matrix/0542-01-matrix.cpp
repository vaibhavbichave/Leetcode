class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dist = 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == 0)
                    visited[i][j] = true, q.push({i, j});
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                pair<int, int> p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                mat[x][y] = dist;
                if (x - 1 >= 0 && !visited[x - 1][y])
                    visited[x - 1][y] = true, q.push({x - 1, y});
                if (x + 1 < n && !visited[x + 1][y])
                    visited[x + 1][y] = true, q.push({x + 1, y});
                if (y - 1 >= 0 && !visited[x][y - 1])
                    visited[x][y - 1] = true, q.push({x, y - 1});
                if (y + 1 < m && !visited[x][y + 1])
                    visited[x][y + 1] = true, q.push({x, y + 1});
            }
            dist++;
        }
        return mat;
    }
};