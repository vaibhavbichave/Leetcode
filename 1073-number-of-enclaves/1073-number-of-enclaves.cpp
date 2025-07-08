class Solution {
public:
    void dfs(vector<vector<int>>& board, int x, int y) {
        board[x][y] = 0;
        int n = board.size(), m = board[0].size();
        if (x - 1 >= 0 && board[x - 1][y])
            dfs(board, x - 1, y);
        if (x + 1 < n && board[x + 1][y])
            dfs(board, x + 1, y);
        if (y - 1 >= 0 && board[x][y - 1])
            dfs(board, x, y - 1);
        if (y + 1 < m && board[x][y + 1])
            dfs(board, x, y + 1);
    }
    int numEnclaves(vector<vector<int>>& board) {
        int count = 0;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0])
                dfs(board, i, 0);
            if (board[i][m - 1])
                dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j])
                dfs(board, 0, j);
            if (board[n - 1][j])
                dfs(board, n - 1, j);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                count += board[i][j];
        return count;
    }
};