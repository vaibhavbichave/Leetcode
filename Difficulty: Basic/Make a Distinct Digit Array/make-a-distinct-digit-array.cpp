//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
   	vector<int> common_digits(vector<int>nums){
   	    vector<int>freq(10, 0);
   	    for(int x:nums){
   	        while(x){
   	            freq[x%10]++;
   	            x/=10;
   	        }
   	    }
       	vector<int>v;
       	for(int i=0;i<10;i++) if(freq[i]>0) v.push_back(i);
        return v;
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < nums.size(); i++)cin >> nums[i];
		Solution ob;
		vector<int> ans = ob.common_digits(nums);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends