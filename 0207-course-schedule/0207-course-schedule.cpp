class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> g(numCourses);
        for (auto x : prerequisites) {
            g[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i]==0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int x : g[top]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        for (int x : indegree)
            if (x > 0)
                return false;
        return true;
    }
};