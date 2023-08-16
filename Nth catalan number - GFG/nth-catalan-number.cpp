//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int findCatalan(int n) 
    {
        int MOD = 1e9+7;
        long int catalan[n + 1];
        catalan[0] = catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            catalan[i] = 0;
            for (int j = 0; j < i; j++)
                catalan[i] = (catalan[i] + (catalan[j] * catalan[i - j - 1]) % MOD ) % MOD;
        }
        return catalan[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends