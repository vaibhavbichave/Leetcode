//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        int n = arr.size();
        vector<int>left(n,0), right(n,INT_MAX);
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], arr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = min(right[i+1], arr[i+1]);
        }
        for(int i=1;i<n-1;i++){
            if(left[i]<arr[i] && arr[i]<right[i]){
                return arr[i];
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends