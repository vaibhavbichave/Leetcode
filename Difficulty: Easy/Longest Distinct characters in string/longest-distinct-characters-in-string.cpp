//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

int longestSubstrDistinctChars (string S)
{
    int result = 0, n = S.size();
    vector<int>v(26, 0);
    for(int i=0, j=0;j<n;j++){
        v[S[j]-'a']++;
        while(v[S[j]-'a']>1) v[S[i++]-'a']--;
        result = max(result, j-i+1);
    }
    return result;
}