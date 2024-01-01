class Solution {
public:
    bool check(string str, string result, int n, int x){
        int i=0;
        while(i<n && str[i]==result[i%x]) i++;
        return i==n;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        for(int i=min(n,m);i>0;i--){
            if(n%i==0 && m%i==0){
                string result = str1.substr(0,i);
                if(check(str1,result,n,i) && check(str2,result,m,i)){
                    return result;
                }
            }
        }
        return "";
    }
};