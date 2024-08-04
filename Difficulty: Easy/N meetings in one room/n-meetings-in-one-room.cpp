//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>>v;
        for(int i=0;i<n;i++) v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), [&](pair<int, int>&a , pair<int, int>&b){
            if(a.second == b.second) return a.first<b.first;
            return a.second<b.second;
        });
        
        vector<pair<int, int>>result;
        result.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(result.back().second<v[i].first){
                result.push_back(v[i]);
            }
        }
        return result.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends