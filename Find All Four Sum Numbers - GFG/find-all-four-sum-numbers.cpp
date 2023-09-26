//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        int n = arr.size();
        set<vector<int> >st;
         vector<vector<int> > v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1,m=n-1,sum = target-arr[i]-arr[j];
                while(k<m){
                    if(sum > arr[k]+arr[m]){
                        k++;
                    }
                    else if(sum < arr[k]+arr[m]){
                        m--;
                    }
                    else{
                        st.insert({arr[i],arr[j],arr[k],arr[m]});
                        k++,m--;
                    }
                }
            }
        }
        for(auto x:st) v.push_back(x);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends