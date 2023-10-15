//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        long long int result = 1, zeros=0;
        vector<long long int> v(n,0);
        for(long long int x:nums){
            if(x==0) zeros++;
            else result *= x;
        } 
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(zeros>1) v[i] = 0;
                else v[i] = result;
            }
            else{
                if(zeros>0) v[i] = 0;
                else v[i] = result/nums[i];
            }
        }
        return v;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends