//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int first(int arr[], int low, int high, int x, int n)
    {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
                return mid;
            else if (x > arr[mid])
                return first(arr, (mid + 1), high, x, n);
            else
                return first(arr, low, (mid - 1), x, n);
        }
        return -1;
    }
    int last(int arr[], int low, int high, int x, int n)
    {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if ((mid == n - 1 || x < arr[mid + 1])
                && arr[mid] == x)
                return mid;
            else if (x < arr[mid])
                return last(arr, low, (mid - 1), x, n);
            else
                return last(arr, (mid + 1), high, x, n);
        }
        return -1;
    }
    vector<int> find(int arr[], int n , int x )
    {
        int a = first(arr, 0, n-1, x, n);
        int b = last(arr, 0, n-1, x, n);
        return {a,b};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends