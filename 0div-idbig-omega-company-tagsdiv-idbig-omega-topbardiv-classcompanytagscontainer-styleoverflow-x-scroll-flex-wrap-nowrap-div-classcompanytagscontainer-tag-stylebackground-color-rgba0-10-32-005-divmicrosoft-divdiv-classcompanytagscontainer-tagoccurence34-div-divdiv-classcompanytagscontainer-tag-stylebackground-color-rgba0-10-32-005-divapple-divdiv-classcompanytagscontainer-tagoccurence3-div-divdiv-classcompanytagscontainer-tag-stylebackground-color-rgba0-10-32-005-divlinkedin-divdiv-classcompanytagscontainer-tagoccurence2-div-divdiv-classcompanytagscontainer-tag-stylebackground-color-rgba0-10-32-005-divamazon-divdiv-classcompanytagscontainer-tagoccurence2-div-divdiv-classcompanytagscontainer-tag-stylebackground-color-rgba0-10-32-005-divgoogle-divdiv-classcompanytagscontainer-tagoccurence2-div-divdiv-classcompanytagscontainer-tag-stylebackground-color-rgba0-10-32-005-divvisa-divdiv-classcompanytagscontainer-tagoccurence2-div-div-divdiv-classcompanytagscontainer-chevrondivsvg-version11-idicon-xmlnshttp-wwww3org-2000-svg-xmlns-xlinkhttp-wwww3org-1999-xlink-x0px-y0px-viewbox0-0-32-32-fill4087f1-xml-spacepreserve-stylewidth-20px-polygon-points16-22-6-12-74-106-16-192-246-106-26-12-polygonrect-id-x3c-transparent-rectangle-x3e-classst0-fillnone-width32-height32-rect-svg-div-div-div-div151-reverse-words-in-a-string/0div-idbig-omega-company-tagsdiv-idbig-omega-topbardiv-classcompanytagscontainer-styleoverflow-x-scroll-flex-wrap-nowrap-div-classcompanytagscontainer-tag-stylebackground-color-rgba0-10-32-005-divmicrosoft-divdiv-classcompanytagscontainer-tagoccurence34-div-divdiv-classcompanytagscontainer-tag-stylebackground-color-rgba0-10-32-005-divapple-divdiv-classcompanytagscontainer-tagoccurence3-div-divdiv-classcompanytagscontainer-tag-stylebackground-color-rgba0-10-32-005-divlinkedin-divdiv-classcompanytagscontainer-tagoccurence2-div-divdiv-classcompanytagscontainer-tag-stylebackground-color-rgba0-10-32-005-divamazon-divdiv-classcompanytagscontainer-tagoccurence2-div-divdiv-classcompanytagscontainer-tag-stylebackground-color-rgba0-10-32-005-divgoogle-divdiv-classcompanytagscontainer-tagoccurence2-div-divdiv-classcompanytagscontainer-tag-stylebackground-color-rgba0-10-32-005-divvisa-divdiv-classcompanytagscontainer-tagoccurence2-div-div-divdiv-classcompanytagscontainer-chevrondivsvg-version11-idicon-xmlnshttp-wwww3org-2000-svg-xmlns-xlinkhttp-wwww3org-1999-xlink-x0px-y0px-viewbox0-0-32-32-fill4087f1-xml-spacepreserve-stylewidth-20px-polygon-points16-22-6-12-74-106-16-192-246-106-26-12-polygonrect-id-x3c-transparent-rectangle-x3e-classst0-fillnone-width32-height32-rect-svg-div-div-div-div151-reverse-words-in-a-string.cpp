class Solution {
public:
    string trim(string s, int n){
        int i=0;
        string ans;
        while(i<n && s[i]==' ') i++; 
        while(i<n){
            while(i<n && s[i]!=' ') ans+=s[i++];
            while(i<n && s[i]==' ') i++; 
            if(i<n) ans+=' ';
        }
        return ans;
    }
    string reverseWords(string s) {
        int i=0,j=0,n=s.size();
        reverse(s.begin(),s.end());
        while(i<n){
            while(j<n && s[j]!=' ') j++;
            reverse(s.begin()+i, s.begin()+j);
            i = ++j; 
        }
        return trim(s, n);
    }
};