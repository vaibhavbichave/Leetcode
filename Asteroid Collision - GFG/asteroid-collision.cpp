//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector<int>v;
        stack<int>st;
        for(int i=0;i<N;i++){
            if(asteroids[i] < 0){
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])) st.pop();
                if(!st.empty()){
                    if(st.top()<0) st.push(asteroids[i]);
                    if(st.top()==abs(asteroids[i])) st.pop();
                }else{
                    st.push(asteroids[i]);
                }
            }else{
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()){v.push_back(st.top());st.pop();}
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends