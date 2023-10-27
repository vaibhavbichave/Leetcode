//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        string ss = s;
        int n = s.size();
        reverse(ss.begin(),ss.end());
        vector<vector<int>>v(n+1,vector<int>(n+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==ss[j-1]) v[i][j] = 1+v[i-1][j-1];
                else v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
        return n-v[n][n];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends