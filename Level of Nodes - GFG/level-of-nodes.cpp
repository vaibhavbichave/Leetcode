//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<bool>visited(V,false);
	    queue<int>q;
	    q.push(0);
	    visited[0]=true;
	    for(int level=0;!q.empty();level++){
	        for(int i=q.size();i>0;i--){
	            int x = q.front();
	            q.pop();
	            if(x==X) return level;
	            for(int y:adj[x]){
	                if(!visited[y]){
	                    q.push(y);
	                    visited[y]=true;
	                }
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends