class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (st.contains(board[i][j]))
                        return false;
                    st.insert(board[i][j]);
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            unordered_set<int> st;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (st.contains(board[i][j]))
                        return false;
                    st.insert(board[i][j]);
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<int> st;
                for (int m = i; m < i + 3; m++) {
                    for (int n = j; n < j + 3; n++) {
                        if (board[m][n] != '.') {
                            if (st.contains(board[m][n]))
                                return false;
                            st.insert(board[m][n]);
                        }
                    }
                }
            }
        }
        return true;
    }
};