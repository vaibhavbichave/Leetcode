//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     void dfs(vector<vector<int>> &grid, int i ,int j, int n, int m){
        if(i>=0 && i<n && j>=0 && j<m){
            if(grid[i][j]){
                grid[i][j]=0;
                dfs(grid,i,j-1,n,m);
                dfs(grid,i,j+1,n,m);
                dfs(grid,i-1,j,n,m);
                dfs(grid,i+1,j,n,m);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            dfs(grid,i,0,n,m);
            dfs(grid,i,m-1,n,m);
        }
        for(int j=0;j<m;j++){
            dfs(grid,0,j,n,m);
            dfs(grid,n-1,j,n,m);
        }
        int result =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result += grid[i][j];
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends