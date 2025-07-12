class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            unordered_set<int> st1;
            for (int x : properties[i])
                st1.insert(x);
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                unordered_set<int> st2;
                for (int x : properties[j])
                    st2.insert(x);
                for (int x : st2)
                    cnt += st1.contains(x);
                if (cnt >= k)
                    g[i].push_back(j), g[j].push_back(i);
            }
        }
        int cnt = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                queue<int> q;
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int it : g[node])
                        if (!visited[it])
                            visited[it] = true, q.push(it);
                }
            }
        }
        return cnt;
    }
};