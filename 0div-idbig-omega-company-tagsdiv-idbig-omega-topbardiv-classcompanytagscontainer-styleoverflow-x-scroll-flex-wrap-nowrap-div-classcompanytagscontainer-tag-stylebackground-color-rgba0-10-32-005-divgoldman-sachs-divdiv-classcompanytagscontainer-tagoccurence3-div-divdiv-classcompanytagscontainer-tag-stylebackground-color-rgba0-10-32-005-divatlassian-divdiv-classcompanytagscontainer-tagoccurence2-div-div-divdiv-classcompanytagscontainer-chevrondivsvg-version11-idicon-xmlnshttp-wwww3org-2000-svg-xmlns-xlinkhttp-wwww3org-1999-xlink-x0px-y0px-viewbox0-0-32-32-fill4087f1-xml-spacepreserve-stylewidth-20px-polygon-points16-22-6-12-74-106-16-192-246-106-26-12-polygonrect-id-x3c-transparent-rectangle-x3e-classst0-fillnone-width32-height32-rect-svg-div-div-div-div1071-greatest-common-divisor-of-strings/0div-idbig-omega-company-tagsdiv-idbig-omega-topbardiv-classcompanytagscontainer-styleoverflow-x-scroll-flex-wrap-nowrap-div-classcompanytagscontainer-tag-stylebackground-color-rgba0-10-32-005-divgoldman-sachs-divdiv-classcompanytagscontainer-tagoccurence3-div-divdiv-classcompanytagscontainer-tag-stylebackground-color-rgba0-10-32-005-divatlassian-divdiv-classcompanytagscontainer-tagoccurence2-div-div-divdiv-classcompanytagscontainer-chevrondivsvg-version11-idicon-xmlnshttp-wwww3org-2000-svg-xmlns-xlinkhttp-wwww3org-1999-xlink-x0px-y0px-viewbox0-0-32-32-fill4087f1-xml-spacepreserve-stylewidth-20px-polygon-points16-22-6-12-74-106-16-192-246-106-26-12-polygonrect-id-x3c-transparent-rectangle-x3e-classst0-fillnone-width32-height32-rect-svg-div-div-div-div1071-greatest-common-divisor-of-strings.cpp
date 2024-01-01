class Solution {
public:
    bool check(string str1, string str2, int n, int m, int x){
        int i=0, j=0;
        while(i<n && str1[i]==str1[i%x]) i++;
        if(i<n) return false;
        while(j<m && str2[j]==str2[j%x]) j++;
        if(j<m) return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        for(int i=__gcd(n,m);i>0;i--){
            if(n%i==0 && m%i==0 && str1.substr(0,i)==str2.substr(0,i)){
                if(check(str1,str2,n,m,i)){
                    return str1.substr(0,i);
                }
            }
        }
        return "";
    }
};