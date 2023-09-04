//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int sign = 1, base = 0, i = 0, n=str.size();
        while (str[i] == ' ') i++;
        if (str[i] == '-') sign = -sign;
        if (str[i] == '-' || str[i] == '+') i++;
        
        while (str[i] >= '0' && str[i] <= '9'){
            int x =str[i++] - '0';
            base = 10 * base + x;
        }
        if(i<n) return -1;
        return base*sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends