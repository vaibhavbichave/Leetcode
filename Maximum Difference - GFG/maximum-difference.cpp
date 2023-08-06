//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      stack<pair<int,int>> s;
      vector<int>l(n,0),r(n,0);
      for(int i=0;i<n;i++){
          while(!s.empty() && s.top().first>A[i]){
              r[s.top().second] = A[i];
              s.pop();
            }
          s.push({A[i],i});
      }
      while(!s.empty()) s.pop();
      for(int i=n-1;i>=0;i--){
          while(!s.empty() && s.top().first>A[i]){
              l[s.top().second] = A[i];
              s.pop();
            }
          s.push({A[i],i});
      }
      int maxi = 0;
      for(int i=0;i<n;i++) maxi = max(maxi,abs(r[i]-l[i]));
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
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends