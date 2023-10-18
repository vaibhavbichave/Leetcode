//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void init(vector<int> graph[], vector<int> &indeg, vector<vector<int>> &adj, int n){
        for(int i=0; i<n ; i++){
            for(int j=graph[i].size()-1; j>=0; j--){
                int v=graph[i][j];
                adj[v].push_back(i);
                indeg[i]++;
            }
        }
    }

    vector<int> eventualSafeNodes(int n, vector<int> graph[]) {
        vector<int> indeg(n, 0);
        vector<bool> safe(n, 0);
        vector<vector<int>> adj(n);
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends