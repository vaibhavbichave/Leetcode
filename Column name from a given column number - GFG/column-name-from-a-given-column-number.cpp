//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        char str[100];
        int i = 0;
     
        while (n > 0) {
            int rem = n % 26;
            if (rem == 0) {
                str[i++] = 'Z';
                n = (n / 26) - 1;
            }
            else{
                str[i++] = (rem - 1) + 'A';
                n = n / 26;
            }
        }
        str[i] = '\0';
        reverse(str, str + strlen(str));
        return str;
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends