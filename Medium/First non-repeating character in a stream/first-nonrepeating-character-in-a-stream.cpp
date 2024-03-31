//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int n = A.size();
            queue<char> q;
            vector<int> count(256, 0);
            for (int i=0;i<n;i++) { 
                count[A[i]]++;
                q.push(A[i]);
                while (!q.empty() && count[q.front()] > 1)  q.pop();
                if (q.empty()) A[i] = '#';
                else A[i] = q.front();
            }
         
            return A; 
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends