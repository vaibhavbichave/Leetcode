//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long mini = arr[0];
	    long long maxi = arr[0];
	    long long result = maxi;
	    for(int i=1;i<n;i++){
	        long long gmaxi = maxi, gmini = mini;
	        maxi = max(1ll*arr[i], max(arr[i]*gmini, arr[i]*gmaxi));
	        mini = min(1ll*arr[i], min(arr[i]*gmini, arr[i]*gmaxi));
	        result = max(result, maxi);
	    }
	    return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends