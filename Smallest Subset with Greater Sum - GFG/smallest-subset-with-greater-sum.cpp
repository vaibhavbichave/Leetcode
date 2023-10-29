//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        long long sum = 0, count = 0, sum2 =0;
        sort(arr.begin(), arr.end(), greater<int>());
        for(int x:arr) sum+=x;
        for(int x:arr) {
            sum2+=x;count++; 
            if(sum2>(sum-sum2)) break;
        }
        return count;
     
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends