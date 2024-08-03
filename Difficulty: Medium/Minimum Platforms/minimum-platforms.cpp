//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        int maxDepartureTime = 2400;
    	int count = 0, maxPlatforms = 0;
        vector<int> v(maxDepartureTime + 2, 0);
        for (int i = 0; i < n; i++) {
            v[arr[i]]++;
            v[dep[i] + 1]--;
        }
        for (int i = 0; i <= maxDepartureTime + 1; i++) {
            count += v[i];
            maxPlatforms = max(maxPlatforms, count);
        }
        return maxPlatforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends