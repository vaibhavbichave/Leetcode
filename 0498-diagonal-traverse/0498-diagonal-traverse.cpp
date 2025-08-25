class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> v;
        int i = 0, j = 0, top = 1;
        int n = mat.size(), m = mat[0].size();
        while (i >= 0 && j >= 0 && i < n && j < m) {
            while (i >= 0 && j >= 0 && i < n && j < m) {
                v.push_back(mat[i][j]);
                if (top) {
                    i--, j++;
                } else {
                    i++, j--;
                }
            }
            if (top) {
                i++;
                if (j >= m) {
                    j--, i++;
                }
            } else {
                j++;
                if (i >= n) {
                    i--, j++;
                }
            }
            top = top ^ 1;
        }
        return v;
    }
};