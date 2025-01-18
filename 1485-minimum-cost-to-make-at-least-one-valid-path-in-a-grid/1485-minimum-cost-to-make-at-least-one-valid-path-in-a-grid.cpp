class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};
        int r = grid.size(), c = grid[0].size();
        auto isvalid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < r && y < c;
        };
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        deque<pair<int, int>> dq;
        dq.emplace_front(0, 0);
        dist[0][0] = 0;
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int i = 1; i <= 4; ++i) {
                int nx = x + dx[i - 1], ny = y + dy[i - 1];
                if (isvalid(nx, ny)) {
                    int cost = (i == grid[x][y]) ? 0 : 1;
                    if (dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;
                        (cost == 0) ? dq.emplace_front(nx, ny)
                                    : dq.emplace_back(nx, ny);
                    }
                }
            }
        }
        return dist[r - 1][c - 1];
    }
};