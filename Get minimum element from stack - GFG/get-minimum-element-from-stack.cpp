//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    stack<pair<int,int>>st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()) return -1;
           return st.top().first;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()) return -1;
           int x = s.top();
           s.pop();
           if(st.top().first==x){
               if(st.top().second==1) st.pop();
               else st.top().second--;
           }
           return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           s.push(x);
           if(!st.empty()){
               if(st.top().first==x) st.top().second++;
               else if(st.top().first>x) st.push({x,1});
           }
           else{
               st.push({x,1});
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends