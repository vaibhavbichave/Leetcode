//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int> &nums, int n, int target, bool findStartIndex) {
    int ans = -1, start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (target < nums[mid]) {
            end = mid - 1;
        } else if (target > nums[mid]) {
            start = mid + 1;
        } else {
            ans = mid;
            if (findStartIndex) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return ans;
}
    vector<int> firstAndLast(int x, vector<int> &arr) {
        vector<int>v;
        int n = arr.size();
        int lower = search(arr, n, x, true);
        if(lower != -1) v.push_back(lower);
        int upper = search(arr, n, x, false);
        if(upper != -1) v.push_back(upper);
        if(v.empty()) v.push_back(-1);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(x, arr);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends