//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int>row(n,0), col(n,0);;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i] += matrix[i][j];
                col[j] += matrix[i][j];
            }
        }
        
        int i=0,j=0,maxi=0, result = 0;
        for(int x:row) maxi = max(maxi, x);
        for(int x:col) maxi = max(maxi, x);
        while(i<n && j<n){
            int mini = min(maxi - row[i], maxi - col[j]);
            result += mini;
            row[i] += mini;
            col[j] += mini;
            if(row[i]==maxi) i++;
            if(col[j]==maxi) j++;
        }
        while(i<n){
            result +=( maxi - row[i]);
            i++;
        }
         while(j<n){
            result += (maxi - col[j]);
            j++;
        }
        return result;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends