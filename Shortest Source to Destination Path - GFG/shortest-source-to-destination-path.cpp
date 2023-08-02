//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&v, vector<vector<int>>&A, int n, int m, int x, int y, int curr){
        if(v[x][y]>curr){
            v[x][y]=curr;
           if(x+1<n && A[x+1][y]==1) dfs(v,A,n,m,x+1,y, curr+1);
           if( y+1<m && A[x][y+1]==1) dfs(v,A,n,m,x,y+1, curr+1);
           if(x-1>=0 && A[x-1][y]==1) dfs(v,A,n,m,x-1,y, curr+1);
           if( y-1>=0 && A[x][y-1]==1) dfs(v,A,n,m,x,y-1, curr + 1);
        }
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>>v(N,vector<int>(M,INT_MAX));
        dfs(v,A,N,M,0,0,0);
        return v[X][Y]==INT_MAX?-1:v[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends