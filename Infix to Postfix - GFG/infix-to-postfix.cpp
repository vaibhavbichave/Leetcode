//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isOperand(char x){
        return x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')';
    } 
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ss;
        stack<pair<char, int>>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            char x = s[i];int precedence;
            if(isOperand(x)){
                if(x=='(') {
                    st.push({x,0});
                    continue;
                }
                else if(x==')'){
                    while(st.top().second!=0){
                        ss+=st.top().first;
                        st.pop();
                    }
                    st.pop();
                    continue;
                }
                if(s[i]=='+' || s[i]=='-') precedence = 1;
                else if(s[i]=='*' || s[i]=='/') precedence=2;
                else if(s[i]=='^') precedence = 3;
                
                    
                while(!st.empty() && st.top().second>=precedence){
                    ss+=st.top().first;
                    st.pop();
                }
                st.push({x,precedence});
                
            }else{
                ss+=s[i];
            }
        }
        while(!st.empty()){
            ss+=st.top().first;
            st.pop();
        }
        return ss;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends