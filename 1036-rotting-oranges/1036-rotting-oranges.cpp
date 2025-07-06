class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (!q.empty())
            count--;
        while (!q.empty()) {
            count++;
            for (int k = q.size(); k > 0; k--) {
                auto [x, y] = q.front();
                q.pop();
                vector<int> dx = {-1, 0, 1, 0};
                vector<int> dy = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int xnxt = x + dx[i], ynxt = y + dy[i];
                    if (xnxt >= 0 && xnxt < n && ynxt >= 0 && ynxt < m &&
                        grid[xnxt][ynxt] == 1) {
                        grid[xnxt][ynxt] = 2;
                        q.push({xnxt, ynxt});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }
};