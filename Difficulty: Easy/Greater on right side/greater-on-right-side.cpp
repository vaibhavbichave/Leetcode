//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Function to replace every element with the
    next greatest element */
    vector<int> nextGreatest(vector<int> arr) {
        stack<int>s;
        vector<int>v(arr.size(), -1);
        for(int i = arr.size()-1;i>=0;i--){
            if(!s.empty()){
                v[i] = s.top();
            }
            while(!s.empty() && s.top()<arr[i]) s.pop();
            if(s.empty() || s.top()<arr[i]) s.push(arr[i]);
        }
        return v;
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
        Solution obj;
        vector<int> ans = obj.nextGreatest(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends