class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q;
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                q.push({i, 0});
                while (!q.empty()) {
                    auto [curr, clr] = q.front();
                    q.pop();
                    for (auto node : graph[curr]) {
                        if (color[node] == clr) {
                            return false;
                        }
                        if (color[node] == -1) {
                            color[node] = clr ^ 1;
                            q.push({node, color[node]});
                        }
                    }
                }
            }
        }
        return true;
    }
};