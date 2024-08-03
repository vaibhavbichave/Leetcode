//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        int n = arr.size();
        int first = -1, second = -1, third = -1;
        for(int i=0;i<n;i++){
            if(first<arr[i]){
                third = second;
                second = first;
                first = arr[i];
            } 
            else if(second<arr[i]){
                third = second;
                second = arr[i];
            } 
            else if(third<arr[i]){
                third = arr[i];
            } 
        }
        return third;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.thirdLargest(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends