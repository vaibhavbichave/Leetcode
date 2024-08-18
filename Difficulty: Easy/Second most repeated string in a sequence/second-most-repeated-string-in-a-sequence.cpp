//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> occ; 
        int first_max = INT_MIN, sec_max = INT_MIN; 
        for (int i = 0; i < n; i++) occ[arr[i]]++; 
        for (auto it : occ) { 
            if (it.second >= first_max) { 
                sec_max = first_max; 
                first_max = it.second; 
            }  else if (it.second > sec_max) 
                sec_max = it.second; 
        } 
        for (auto it : occ) {
            if (it.second == sec_max) {
                return it.first;
            }
        }
        return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends