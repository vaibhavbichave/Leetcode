//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int l, int p, int q, int r)
    {
        int dp[l + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i <= l; i++) {
            if (dp[i] == -1)
                continue;
            if (i + p <= l)
                dp[i + p] = max(dp[i + p], dp[i] + 1);
            if (i + q <= l)
                dp[i + q] = max(dp[i + q], dp[i] + 1);
            if (i + r <= l)
                dp[i + r] = max(dp[i + r], dp[i] + 1);
        }
        if (dp[l] == -1) {
            dp[l] = 0;
        }
        return dp[l];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends