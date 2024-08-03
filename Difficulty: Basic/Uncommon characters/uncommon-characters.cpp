//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B) {
            string result;
            vector<bool>a(26, false);
            vector<bool>b(26, false);
            for(char x:A) a[x-'a']=true;
            for(char x:B) b[x-'a']=true;
            for(int i=0;i<26;i++){
                if(a[i]^b[i]){
                    result+=('a'+i);
                }
            }
            sort(result.begin(), result.end());
            if(result.empty()) return "-1";
            return result;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends