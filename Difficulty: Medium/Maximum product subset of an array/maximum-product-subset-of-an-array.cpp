//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long findMaxProduct(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        long long negative_count = 0, positive_count = 0, mod = 1e9 + 7;
        long long positive_poduct = 1, negative_product = 1, max_negative = INT_MIN;
        for (long long x : arr) {
            if (x < 0) {
                negative_product = (negative_product * x) % mod;
                max_negative = max(x, max_negative);
                negative_count++;
            }
            if (x > 0) {
                positive_poduct = (positive_poduct * x) % mod;
                positive_count++;
            }
        }
        if (negative_count <= 1 && positive_count == 0) return 0;
        if (negative_product < 0) negative_product /= max_negative;
        return (positive_poduct * negative_product) % mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends