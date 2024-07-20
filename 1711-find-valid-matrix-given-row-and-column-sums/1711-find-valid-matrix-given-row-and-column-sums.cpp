class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> result(n, vector<int>(m, 0));
        for (int i = 0, j = 0; i < n && j < m;
             i += (rowSum[i] == 0), j += (colSum[j] == 0)) {
            int mini = min(rowSum[i], colSum[j]);
            result[i][j] = mini;
            rowSum[i] -= mini;
            colSum[j] -= mini;
        }
        return result;
    }
};