//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    int mini = INT_MAX, n = s.size();
    vector<int>v(26, INT_MAX);
    for(int i=n-1;i>=0;i--){
        int index = s[i]-'a';
        if(v[index] != INT_MAX){
            mini = min(mini, v[index]);
        }
        v[index] = i;
    }
    string result;
    if(mini != INT_MAX) result += s[mini];
    else result = "-1";
    return result;
}