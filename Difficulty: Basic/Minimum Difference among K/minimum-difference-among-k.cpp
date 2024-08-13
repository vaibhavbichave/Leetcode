//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minDiff(vector<int>& arr, int k) {
        int mini = INT_MAX, n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n-k+1;i++){
            mini = min(mini, arr[i+k-1] - arr[i]);
        }
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        cout << obj.minDiff(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends