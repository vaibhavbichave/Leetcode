//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string ss;
        stack<char>st;
        for(auto x:s) {
            if(x!='.') st.push(x);
            else{
                while(!st.empty()){
                    ss+=st.top();
                    st.pop();
                }
                ss+='.';
            }
        }
        while(!st.empty()){
            ss+=st.top();
            st.pop();
        }
        return ss;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends