//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string str)
    {
        stack<char>s;
        for(char x: str){
            if(x == '(' || x == '{' || x == '['){
                s.push(x);
            } else if(x == ')') {
                if(!s.empty() && s.top()=='(') s.pop();
                else return false;
            } else if(x == '}'){
                if(!s.empty() && s.top()=='{') s.pop();
                    else return false;
            } else if(x == ']'){
                if(!s.empty() && s.top()=='[') s.pop();
                else return false;
            } else {
                return false;
            }
        }
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends