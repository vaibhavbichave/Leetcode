class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node,
             int curr) {
        if (color[node] == -1) {
            color[node] = curr;
            for (int x : graph[node]) {
                if (!dfs(graph, color, x, curr ^ 1))
                    return false;
            }
        } else if (color[node] != curr) {
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q;
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(graph, color, i, 0))
                    return false;
            }
        }
        return true;
    }
};