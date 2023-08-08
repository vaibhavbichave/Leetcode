//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        stack<int>s1,s2,s3;
        for(int i=N1-1;i>=0;i--) {
            s1.push(S1[i]);
            if(i>0) S1[i-1]+=S1[i];
        }
        for(int i=N2-1;i>=0;i--) {
            s2.push(S2[i]);
            if(i>0) S2[i-1]+=S2[i];
        }
        for(int i=N3-1;i>=0;i--) {
            s3.push(S3[i]);
            if(i>0) S3[i-1]+=S3[i];
        }
        while(!s1.empty() && !s2.empty() && !s3.empty() &&  (s1.top()!= s2.top() || s1.top()!=s3.top())){
            while(!s1.empty() && !s2.empty() && s1.top() != s2.top()){
                if(s1.top()>s2.top()) s1.pop();
                else s2.pop();
            }
            while(!s1.empty() && !s3.empty() && s1.top() != s3.top()){
                if(s1.top()>s3.top()) s1.pop();
                else s3.pop();
            }
        }
        if(!s1.empty() && !s2.empty() && !s3.empty() &&  s1.top()== s2.top() && s1.top()==s3.top()) return s1.top();
        
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends