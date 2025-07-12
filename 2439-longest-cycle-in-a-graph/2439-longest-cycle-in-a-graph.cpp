class Solution {
private:
    void dfs(vector<int>& edges, vector<int>& path, vector<bool>& visited,
             int node, int& res, int cnt) {
        visited[node] = true;
        path[node] = cnt;
        if (edges[node] != -1) {
            int it = edges[node];
            if (!visited[it])
                dfs(edges, path, visited, it, res, cnt + 1);
            else if (path[it])
                res = max(res, cnt - path[it] + 1);
        }
        path[node] = 0;
    }

public:
    int longestCycle(vector<int>& edges) {
        int res = -1, n = edges.size();
        vector<bool> visited(n, false);
        vector<int> path(n, 0);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(edges, path, visited, i, res, 1);
        return res;
    }
};