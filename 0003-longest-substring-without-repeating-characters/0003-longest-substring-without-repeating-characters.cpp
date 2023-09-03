class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size(), count=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            j++;
            count = max(count, j-i);
        }
        return count;
    }
};