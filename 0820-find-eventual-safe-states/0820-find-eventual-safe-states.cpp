class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited,
             vector<bool>& path, vector<bool>& topo, int node) {
        visited[node] = true;
        path[node] = true;
        for (auto it : graph[node]) {
            if (!visited[it]) {
                if (dfs(graph, visited, path, topo, it))
                    return true;
            } else if (path[it])
                return true;
        }
        topo[node] = true;
        path[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false), path(n, false), topo(n, false);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(graph, visited, path, topo, i);
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (topo[i])
                res.push_back(i);
        return res;
    }
};