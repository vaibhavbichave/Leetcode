class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = 0, col = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> result(n * m);
        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];
            if ((row + col) & 1) {
                if (row == n - 1) col++;
                else if (col == 0) row++;
                else row++, col--;
            } else {
                if (col == m - 1) row++;
                else if (row == 0) col++;
                else col++, row--;
            }
        }
        return result;
    }
};