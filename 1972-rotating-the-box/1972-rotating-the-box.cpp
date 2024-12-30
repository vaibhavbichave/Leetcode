class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> res(m, vector<char>(n, '.'));
        for (int r = n - 1; r >= 0; r--) {
            for (int i = m - 1, c = m - 1; c >= 0; c--) {
                if (box[r][c] == '#') {
                    res[i][n - r - 1] = '#';
                    i--;
                } else if (box[r][c] == '*') {
                    res[c][n - r - 1] = '*';
                    i = c - 1;
                }
            }
        }
        return res;
    }
};