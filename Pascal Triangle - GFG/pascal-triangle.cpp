//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        int MOD = 1e9+7;
        vector<ll>v(1,1);
        for(int i=1;i<n;i++){
            vector<ll>vv(i+1,1);
            for(int j=1;j<v.size();j++){
                vv[j]=(v[j]+v[j-1])%MOD;
            }
            v = vv;
        }
        return v;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends