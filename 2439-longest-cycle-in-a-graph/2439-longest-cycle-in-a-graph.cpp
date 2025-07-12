class Solution {
private:
    void dfs(vector<vector<int>>& g, vector<int>& path, vector<bool>& visited,
             int node, int& res, int cnt) {
        visited[node] = true;
        path[node] = cnt;
        for (auto it : g[node]) {
            if (!visited[it]) {
                dfs(g, path, visited, it, res, cnt + 1);
            } else if (path[it]) {
                res = max(res, cnt - path[it] + 1);
            }
        }
        path[node] = 0;
    }

public:
    int longestCycle(vector<int>& edges) {
        int res = -1, n = edges.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
            if (edges[i] != -1)
                g[i].push_back(edges[i]);
        vector<bool> visited(n, false);
        vector<int> path(n, 0);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(g, path, visited, i, res, 1);
        return res;
    }
};