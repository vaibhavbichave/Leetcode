class Solution {
public:
    string longestPalindrome(string s) {
        int st=0, len=0;
        int max_len=0, n=s.size();
        
        // Odd String
        for(int i=0;i<n;i++){
            int l=i, r=i;
            while(l>=0 && r<n){
                if(s[l]==s[r]) l--, r++;
                else break;
            }
            int len = r-l-1;
            if(max_len<len){
                st = l+1;
                max_len = len;
            }
        }
        
        // Even String
        for(int i=0;i<n;i++){
            int l=i, r=i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]) l--, r++;
                else break;
            }
            int len = r-l-1;
            if(max_len<len){
                st = l+1;
                max_len = len;
            }   
        }
        
        return s.substr(st,max_len);
    }
};