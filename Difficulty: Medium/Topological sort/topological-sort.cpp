//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int> topoSort(int v, vector<int> graph[]) {
	    vector<int> answer;
        vector<int> indegree(v,0);
        queue<int> q;
        
        for(int i=0; i<v; i++){
            for(auto j : graph[i]){
                indegree[j]++;
            }
        }
        
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
                
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            answer.push_back(current);
            for(auto j : graph[current]) {
                indegree[j]--;
                if(indegree[j] == 0){
                    q.push(j);
                }
            }
        }
        return answer;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends