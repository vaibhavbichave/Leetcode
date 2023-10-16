//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        long long int result = 0, mini = 1e9+1;
        vector<long long int>v;
        for(int i=0;i<n;i++){
            if(a[i]<0) v.push_back(a[i]);
            else result+=a[i];
            mini = min(mini, abs(a[i]));
        }
        sort(v.begin(),v.end());
        int vsz = v.size();
        for(int i=0;i<vsz;i++){
            if(k-->0) result-= v[i];
            else result+= v[i];
        }
        if(k>0 && k&1) result -= 2*mini;
        return result;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends