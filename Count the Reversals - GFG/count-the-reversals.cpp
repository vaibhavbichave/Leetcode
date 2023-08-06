//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int n = s.size();
    if(n&1) return -1;
    stack<char>st;
    for(char x:s){
        if(x=='}'){
            if(!st.empty() && st.top()=='{') st.pop();
            else st.push(x);
        } 
        else st.push(x);
    }
    int y = st.size();
    while(!st.empty() && st.top()=='{') st.pop();
    int z = st.size();
    y -= z;
    return z/2+(z-2*(z/2))+y/2+(y-2*(y/2));
    
}