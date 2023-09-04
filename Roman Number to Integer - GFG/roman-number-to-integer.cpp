//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  int value(char &x){
        if(x=='I') return 1;
        if(x=='V') return 5;
        if(x=='X') return 10;
        if(x=='L') return 50;
        if(x=='C') return 100;
        if(x=='D') return 500;
        if(x=='M') return 1000;
        return 0;
    }
    int romanToDecimal(string &s) {
        int result = 0, n = s.size();
        for(int i=0;i<n;i++){
            int s1 = 0, s2 = 0;
            s1 = value(s[i]);
            if(i+1<n){
                s2 = value(s[i+1]);
                if(s1>=s2) result += s1;
                else result += (s2-s1),i++;  
            }
            else{
                result += s1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends