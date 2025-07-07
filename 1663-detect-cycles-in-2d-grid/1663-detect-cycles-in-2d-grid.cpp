class Solution {
public:
    bool bfs(int curr, vector<vector<int>>& adjList, vector<bool>& visited) {
        if (!visited[curr]) {
            queue<pair<int, int>> q;
            q.push({curr, -1});
            visited[curr] = true;
            while (!q.empty()) {
                auto [curr, parent] = q.front();
                q.pop();
                for (int neighbor : adjList[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, curr});
                    } else if (neighbor != parent) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int nodes = n * m;
        vector<vector<int>> adjList(nodes);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int current = i * m + j;
                if (i + 1 < n && grid[i][j] == grid[i + 1][j]) {
                    adjList[current].push_back((i + 1) * m + j);
                    adjList[(i + 1) * m + j].push_back(current);
                }
                if (j + 1 < m && grid[i][j] == grid[i][j + 1]) {
                    adjList[current].push_back(i * m + (j + 1));
                    adjList[i * m + (j + 1)].push_back(current);
                }
            }
        }
        vector<bool> visited(nodes, false);
        for (int i = 0; i < nodes; i++) {
            if (bfs(i, adjList, visited)) {
                return true;
            }
        }
        return false;
    }
};