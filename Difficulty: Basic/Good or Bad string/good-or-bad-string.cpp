//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isVowel(char x){
        return x=='a' || x=='e' || x=='i' || x=='o' || x=='u';
    }
    int isGoodorBad(string S) {
        int i=0, j=0, n = S.size();
        while(i<n){
            if(isVowel(S[i])){
                for(j=1;j<=5 && i+j<n;j++){
                    if(!isVowel(S[i+j]) && S[i+j]!='?') {
                        break;
                    }   
                }
                if(j > 5) return 0;
            } else {
                for(j=1;j<=3 && i+j<n;j++){
                    if(isVowel(S[i+j]) && S[i+j]!='?') {
                        break;
                    }   
                }
                if(j > 3) return 0;
            }
            i+=j;
        }
        return 1;
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
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends