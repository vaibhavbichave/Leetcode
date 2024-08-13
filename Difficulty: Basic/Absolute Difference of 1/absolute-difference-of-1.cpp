//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDigitDiff1AndLessK(vector<int>& arr, int k) {
        vector<int>v;
        for(int x:arr){
            if(x<k){
                if(x<10) continue;
                int original = x;
                int rem = -1;
                while(x>0 && (rem<0 || abs(x%10-rem)==1)){
                    rem = x%10;
                    x/=10;
                } 
                if(x==0) v.push_back(original);
            }
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.getDigitDiff1AndLessK(arr, k);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends