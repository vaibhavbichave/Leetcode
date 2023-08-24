//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2) {
        string s = "";
        if((num1.at(0) == '-' || num2.at(0) == '-') && (num1.at(0) != '-' || num2.at(0) != '-' )) s+='-';
        if(num1.at(0) == '-')
            num1 = num1.substr(1);
       
        if(num2.at(0) == '-')
            num2 = num2.substr(1);
            
        int len1 = num1.size();
        int len2 = num2.size();
        if (len1 == 0 || len2 == 0) return "0";
        vector<int> result(len1 + len2, 0);
        int i_n1 = 0, i_n2 = 0;
        for (int i=len1-1; i>=0; i--)
        {
            int carry = 0;
            int n1 = num1[i] - '0';
            i_n2 = 0;       
            for (int j=len2-1; j>=0; j--)
            {
                int n2 = num2[j] - '0';
                int sum = n1*n2 + result[i_n1 + i_n2] + carry;
                carry = sum/10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }
            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }
 
        int i = result.size() - 1;
        while (i>=0 && result[i] == 0) i--;
        if (i == -1) return "0";
        while (i >= 0) s += to_string(result[i--]);
        return s;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends