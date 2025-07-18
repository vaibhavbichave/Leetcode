class Solution {
private:
    long long dfs(vector<vector<int>>& g, vector<int>& cost, int& res, int node,
                  int parent) {
        vector<int> score;
        for (int child : g[node])
            if (child != parent)
                score.push_back(dfs(g, cost, res, child, node));
        if (score.empty())
            return cost[node];
        long long maxi = *max_element(score.begin(), score.end());
        for (int v : score)
            res += (maxi > v);
        return cost[node] + maxi;
    };

public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(g, cost, res, 0, -1);
        return res;
    }
};