//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int grayToBinary(int n) {
        string b, g;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) b.push_back('1');
            else b.push_back('0');
        }
    
        g += b[31];
        int a = b[31] - '0';
        for (int i = 30; i >= 0; i--) {
            int x = b[i] - '0';
            if (a ^ x) g.push_back('1'), a = 1;
            else g.push_back('0'), a = 0;
        }
    
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = ans * 2 + (g[i] - '0');
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends