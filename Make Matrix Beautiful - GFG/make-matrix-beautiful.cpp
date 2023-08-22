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
        
        int i=0,j=0,maxi=0, result = 0;
        vector<int>row(n,0), col(n,0);;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i] += matrix[i][j];
                col[j] += matrix[i][j];
            }
        }
        for(int x:row) maxi = max(maxi, x);
        for(int x:col) maxi = max(maxi, x);
        while(i<n && j<n){
            int diff = 0;
            if(row[i] > col[j]){
                diff = maxi - row[i];
                col[j] += diff;
                i++;
            }else if(row[i] < col[j]){
                diff = maxi - col[j];
                row[i] += diff;
                j++;
            }else{
                diff = maxi - col[j];
                i++; j++;
            }
            result += diff;
        }
        while(i<n){
            result += (maxi - row[i]);
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