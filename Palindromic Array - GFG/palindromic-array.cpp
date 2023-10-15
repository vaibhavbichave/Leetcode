//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool check(int x){
        string str = to_string(x);
        int i=0,j=str.size()-1;
        while(i<j) if(str[i++]!=str[j--]) return false;
        return true;
    }
    int PalinArray(int a[], int n)
    {
        for(int i=0;i<n;i++){
            if(!check(a[i])){
                return 0;
            }
        }
        return 1;
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
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends