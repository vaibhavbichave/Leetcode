//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int missingNumber(int n, vector<int> &arr) {
        int result = n;
        for(int i=0;i<n-1;i++){
            result = result xor (i+1);
            result = result xor arr[i];
        }
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n-1);
        Array::input(arr,n-1);
        
        Solution obj;
        int res = obj.missingNumber(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends