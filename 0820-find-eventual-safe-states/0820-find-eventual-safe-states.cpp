class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        vector<bool> safe(n, false);
        for (int i = 0; i < n; i++) {
            for (int it : graph[i]) {
                adj[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for (int it : adj[node]) {
                --indeg[it];
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (safe[i])
                ans.push_back(i);
        return ans;
    }
};