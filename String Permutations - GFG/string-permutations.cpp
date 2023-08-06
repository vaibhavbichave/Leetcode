//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void f( vector<string>&v, string &s, int idx, int n){
        if(idx+1==n) {v.push_back(s);return;}
        for(int i=idx;i<n;i++){
            swap(s[idx],s[i]);
            f(v,s,idx+1,n);
            swap(s[idx],s[i]);
        }
    }
    vector<string> permutation(string s)
    {
        vector<string>v;
        f(v,s,0,s.size());
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends