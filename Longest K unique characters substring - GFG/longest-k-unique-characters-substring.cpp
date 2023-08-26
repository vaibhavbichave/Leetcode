//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        map<char,int>mp;
        int i=0,j=0,n=s.size(), result = -1;
        while(i<n && j<n){
            if (mp.size()<=k){
                mp[s[j]]++;
                j++;
            }
            else if(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k){ 
                result = max(result, j-i);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends