class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        for (auto prerequisite : prerequisites) {
            indegree[prerequisite[0]]++;
            g[prerequisite[1]].push_back(prerequisite[0]);
        }
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int it : g[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (res.size() == n)
            return res;
        return {};
    }
};