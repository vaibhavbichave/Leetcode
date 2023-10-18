class Solution {
public:
    void init(vector<vector<int>>& graph, vector<int> &indeg, vector<vector<int>> &adj, int n){
        for(int i=0; i<n ; i++){
            for(int j=graph[i].size()-1; j>=0; j--){
                int v=graph[i][j];
                adj[v].push_back(i);
                indeg[i]++;
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        vector<bool> safe(n, 0);
        init(graph,indeg,adj, n);
        queue<int> q;

        for(int i=n-1; i>=0; i--) if (indeg[i]==0) q.push(i);

        while(!q.empty()){
            int x=q.front();
            q.pop();
            safe[x]=1;
            for(int y: adj[x]) if (--indeg[y]==0) q.push(y);
        }
        vector<int> ans;
        for(int i=0; i<n; i++) if (safe[i]) ans.push_back(i);
        return ans;
    }
};