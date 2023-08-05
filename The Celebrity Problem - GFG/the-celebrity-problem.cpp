//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int a,b, c;
        stack<int>s;
        for(int i=0;i<n;i++) s.push(i);
        while(!s.empty()){
            a  = -1 , b= -1;
            if(!s.empty()) {a = s.top();s.pop();}
            if(!s.empty()) {b = s.top();s.pop();}
            if(b != -1) {
                if( M[a][b] == 1) s.push(b);
                else s.push(a);
            }else{
                c = a;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=c && (!M[i][c] || M[c][i])) return -1;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends