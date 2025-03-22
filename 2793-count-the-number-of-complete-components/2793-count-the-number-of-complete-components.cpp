class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> v(n);
        for (auto x : edges) {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int graphSize = 0;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    graphSize += q.size();
                    for (int i = q.size(); i > 0; i--) {
                        int front = q.front();
                        q.pop();
                        for (int x : v[front]) {
                            if (!visited[x]) {
                                q.push(x);
                                visited[x] = true;
                            }
                        }
                    }
                }
                bool flag = true;
                if (v[i].size() != graphSize - 1)
                    flag = false;
                for (int x : v[i])
                    if (v[x].size() != graphSize - 1)
                        flag = false;
                count += flag;
            }
        }
        return count;
    }
};