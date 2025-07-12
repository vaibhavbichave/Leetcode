class Solution {
private:
    void dfs(vector<vector<int>>& g, vector<bool>& visited, vector<int>& path,
             int node, int cnt) {
        visited[node] = true;
        path[node] = cnt;
        for (int it : g[node])
            if (!visited[it])
                dfs(g, visited, path, it, cnt + 1);
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
            if (edges[i] != -1)
                g[i].push_back(edges[i]);
        vector<int> path1(n, INT_MAX), path2(n, INT_MAX);
        vector<bool> visited1(n, false), visited2(n, false);
        dfs(g, visited1, path1, node1, 0);
        dfs(g, visited2, path2, node2, 0);
        int res = -1, mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (path1[i] != INT_MAX && path2[i] != INT_MAX &&
                mini > max(path1[i], path2[i])) {
                mini = max(path1[i], path2[i]);
                res = i;
            }
        }
        return res;
    }
};