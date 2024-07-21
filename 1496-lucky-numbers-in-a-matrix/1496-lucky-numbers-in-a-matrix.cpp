class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> col, row, res;
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < m; j++) {
                mini = min(mini, matrix[i][j]);
            }
            row.push_back(mini);
        }
        for (int j = 0; j < m; j++) {
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, matrix[i][j]);
            }
            col.push_back(maxi);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j])
                    res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};