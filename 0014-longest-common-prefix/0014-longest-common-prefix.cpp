class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string a = strs[0], b = strs[n-1], result;
        int sz = min(a.size(),b.size());
        for(int i=0;i<sz;i++){
            if(a[i]==b[i]) result+=a[i];
            else break;
        }
        return result;
    }
};