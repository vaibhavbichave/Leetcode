//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    bool isUnique(int n){
        vector<int>v(10, 0);
        while(n) {v[n%10]++; n/=10;}
        for(int i=0;i<10;i++) if(v[i]>1) return false;
        return true;
    }
    vector<int> uniqueNumbers(int L,int R)
    {
        vector<int>v;
        for(int i=L;i<=R;i++){
            if(isUnique(i)){
                v.push_back(i);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends