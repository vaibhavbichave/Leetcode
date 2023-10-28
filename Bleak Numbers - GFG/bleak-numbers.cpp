//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
     int countSetBits(int x){
        unsigned int count = 0;
        while (x) {
            count+=x&1;
            x/=2;
        }
        return count;
    }
    bool is_bleak(int n){
        for (int x = n - 32; x < n; x++)
            if (x + countSetBits(x) == n)
                return false;
     
        return true;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends