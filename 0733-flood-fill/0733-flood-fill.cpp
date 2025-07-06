class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int n, int m, int prev,
             int color) {
        if (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == prev) {
            image[i][j] = color;
            dfs(image, i - 1, j, n, m, prev, color);
            dfs(image, i + 1, j, n, m, prev, color);
            dfs(image, i, j - 1, n, m, prev, color);
            dfs(image, i, j + 1, n, m, prev, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (color == image[sr][sc])
            return image;
        int n = image.size(), m = image[0].size();
        dfs(image, sr, sc, n, m, image[sr][sc], color);
        return image;
    }
};