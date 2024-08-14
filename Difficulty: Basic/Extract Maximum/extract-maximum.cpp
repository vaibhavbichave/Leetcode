//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
  public:
    
    int extractMaximum(string S) 
    { 
        int maxi = -1, i = 0, n = S.size();
        while(i<n) {
            int flag = 0, val = 0;
            while(isdigit(S[i])){
                flag = 1;
                val *= 10;
                val += S[i++] - '0'; 
            }
            if(flag>0){
                maxi = max(maxi, val);
            }
            i++;
        }
        return maxi;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.extractMaximum(S)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends