//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long int result=0;
    sort(arr, arr+n);
    int i=0,j=n-1, flag = 1;
    while(i<j){
        if(flag){
            result += abs(arr[j]-arr[i]);
            i++;
        }else{
            result += abs(arr[j]-arr[i]);
            j--;
        }
        flag = !flag;
    }
    if(n&1) result+=abs(arr[i]-arr[0]);
    else result+=abs(arr[j]-arr[0]);
    return result;
}