//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
        int reverse = 0;
        while(n) {
            reverse *= 10;
            if(n%10==0) reverse += 5;
            else reverse += n%10;
            n /= 10;
        }
        
        while(reverse) {
            n *= 10;
            n += reverse%10;
            reverse /= 10;
        }
        return n;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends