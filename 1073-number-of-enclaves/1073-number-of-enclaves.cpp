class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int count = 0;
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0])
                board[i][0] = 0, q.push({i, 0});
            if (board[i][m - 1])
                board[i][m - 1] = 0, q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j])
                board[0][j] = 0, q.push({0, j});
            if (board[n - 1][j])
                board[n - 1][j] = 0, q.push({n - 1, j});
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x - 1 >= 0 && board[x - 1][y])
                board[x - 1][y] = 0, q.push({x - 1, y});
            if (x + 1 < n && board[x + 1][y])
                board[x + 1][y] = 0, q.push({x + 1, y});
            if (y - 1 >= 0 && board[x][y - 1])
                board[x][y - 1] = 0, q.push({x, y - 1});
            if (y + 1 < m && board[x][y + 1])
                board[x][y + 1] = 0, q.push({x, y + 1});
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                count += board[i][j];
        return count;
    }
};