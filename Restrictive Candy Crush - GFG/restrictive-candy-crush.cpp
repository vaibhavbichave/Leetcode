//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        string ss;
        int n = s.size();
        stack<pair<char, int>>st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty() && st.top().first==s[i]) st.top().second++;
            else st.push({s[i],1});
            st.top().second%=k;
            while(!st.empty() && st.top().second%k==0) st.pop();
        }
        while(!st.empty()){
            while(st.top().second--){
                ss+=st.top().first;
            }
            st.pop();
        }
        return ss;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends