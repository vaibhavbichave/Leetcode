class Solution {
public:
    vector<int> topo_sort(int k, vector<vector<int>>& conditions) {
        vector<int> indegree(k + 1, 0);
        vector<vector<int>> g(k + 1);
        for (auto& edge : conditions) {
            int v = edge[0], w = edge[1];
            g[v].push_back(w);
            indegree[w]++;
        }
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        vector<int> ans(k, 0);
        while (!q.empty()) {
            int j = q.front();
            q.pop();
            ans[count++] = j;
            for (int k : g[j]) {
                indegree[k]--;
                if (indegree[k] == 0) {
                    q.push(k);
                }
            }
        }
        if (count != k)
            return {};
        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> order_row = topo_sort(k, rowConditions);
        vector<int> order_col = topo_sort(k, colConditions);

        if (!order_row.empty() && !order_col.empty()) {
            vector<vector<int>> arr(k, vector<int>(k));
            vector<int> pos_i(k + 1, -1), pos_j(k + 1, -1);
            for (int i = 0; i < k; i++)
                pos_i[order_row[i]] = i;
            for (int i = 0; i < k; i++)
                pos_j[order_col[i]] = i;
            for (int x = 1; x <= k; x++)
                arr[pos_i[x]][pos_j[x]] = x;
            return arr;
        }
        return {};
    }
};
