class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = 'V';
        int n = board.size(), m = board[0].size();
        if (x - 1 >= 0 && board[x - 1][y] == 'O')
            dfs(board, x - 1, y);
        if (x + 1 < n && board[x + 1][y] == 'O')
            dfs(board, +-1, y);
        if (y - 1 >= 0 && board[x][y - 1] == 'O')
            dfs(board, x, y - 1);
        if (y + 1 < m && board[x][y + 1] == 'O')
            dfs(board, x, y + 1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') 
                dfs(board, i, 0);
            if (board[i][m - 1] == 'O') 
                dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') 
                dfs(board, 0, j);
            if (board[n - 1][j] == 'O') 
                dfs(board, n - 1, j);
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
            

    }
};