//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if (n == 0) return 0;
  
        int value1 = arr[0];
        if (n == 1) return value1;
      
        int value2 = max(arr[0], arr[1]);
        if (n == 2) return value2;
      
        int max_val;
        for (int i = 2; i < n; i++) {
            max_val = max(arr[i] + value1, value2);
            value1 = value2;
            value2 = max_val;
        }
      
        return max_val;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends