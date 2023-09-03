//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void fill(vector<vector<char>>& mat, int i, int j, int n, int m){
        if(i>=0 && i<n && j>=0 && j<m){
            if(mat[i][j]=='O'){
                mat[i][j]='P';
                fill(mat,i-1,j,n,m);
                fill(mat,i+1,j,n,m);
                fill(mat,i,j-1,n,m);
                fill(mat,i,j+1,n,m);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++) fill(mat,i,0, n, m);
        for(int i=0;i<n;i++) fill(mat,i,m-1, n, m);
        for(int j=0;j<m;j++) fill(mat,0,j, n, m);
        for(int j=0;j<m;j++) fill(mat,n-1,j, n, m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }
                if(mat[i][j]=='P'){
                    mat[i][j]='O';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends