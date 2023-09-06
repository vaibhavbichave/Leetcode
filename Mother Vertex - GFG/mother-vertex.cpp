//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void DFSUtil(int v, vector<bool>& visited, vector<int>adj[])
    {
        visited[v] = true;
        for (auto x: adj[v]){
            if (!visited[x]){
                DFSUtil(x, visited, adj);
            }
        }
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false);
        int v = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited, adj);
                v = i;
            }
        }
        fill(visited.begin(), visited.end(), false);
        DFSUtil(v, visited,adj);
        for (int i = 0; i < V; i++){
            if (!visited[i]){
                return -1;
            }
        }
        return v;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends