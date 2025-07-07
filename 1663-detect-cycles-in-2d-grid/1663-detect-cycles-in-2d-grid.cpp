class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '#') {
                    q.push({i, j});
                    char c = grid[i][j];
                    while (!q.empty()) {
                        auto [first, second] = q.front();
                        if (grid[first][second] == '#')
                            return true;
                        grid[first][second] = '#';
                        q.pop();
                        if (first + 1 < n && grid[first + 1][second] == c) 
                            q.push({first + 1, second});
                        if (first - 1 >= 0 && grid[first - 1][second] == c) 
                            q.push({first - 1, second});
                        if (second + 1 < m && grid[first][second + 1] == c) 
                            q.push({first, second + 1});
                        if (second - 1 >= 0 && grid[first][second - 1] == c) 
                            q.push({first, second - 1});
                    }
                }
            }
        }
        return false;
    }
};