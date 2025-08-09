class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), inbox(9, 0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int curr = board[i][j] - '0';
                    int mask = 1 << curr, idx = (i / 3) * 3 + j / 3;
                    if ((row[i] & mask) || (col[j] & mask) || (inbox[idx] & mask))
                        return false;
                    row[i] |= mask, col[j] |= mask, inbox[idx] |= mask;
                }
            }
        }
        return true;
    }
};