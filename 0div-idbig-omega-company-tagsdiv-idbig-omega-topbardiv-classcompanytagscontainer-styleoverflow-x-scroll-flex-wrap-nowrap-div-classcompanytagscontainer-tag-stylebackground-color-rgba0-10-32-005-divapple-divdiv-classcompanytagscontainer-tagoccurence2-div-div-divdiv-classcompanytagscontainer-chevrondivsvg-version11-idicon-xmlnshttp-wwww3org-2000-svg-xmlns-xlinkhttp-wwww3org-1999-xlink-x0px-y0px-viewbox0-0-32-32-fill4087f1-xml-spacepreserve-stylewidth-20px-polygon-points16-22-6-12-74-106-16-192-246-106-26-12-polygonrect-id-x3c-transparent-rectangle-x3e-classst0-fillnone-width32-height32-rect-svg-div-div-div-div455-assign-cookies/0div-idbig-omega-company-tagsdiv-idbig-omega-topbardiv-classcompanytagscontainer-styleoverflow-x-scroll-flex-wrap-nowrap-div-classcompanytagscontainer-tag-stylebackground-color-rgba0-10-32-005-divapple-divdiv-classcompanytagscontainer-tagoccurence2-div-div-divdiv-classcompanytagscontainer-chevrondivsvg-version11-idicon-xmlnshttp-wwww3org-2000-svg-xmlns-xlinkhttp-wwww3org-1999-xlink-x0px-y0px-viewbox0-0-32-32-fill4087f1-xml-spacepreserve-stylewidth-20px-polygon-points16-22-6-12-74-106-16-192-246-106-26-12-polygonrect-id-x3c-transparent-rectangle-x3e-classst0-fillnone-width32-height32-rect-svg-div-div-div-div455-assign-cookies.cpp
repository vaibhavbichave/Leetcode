class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0, i=0, n = g.size(), m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int j=0;j<m && i<n;j++){
            if(s[j]>=g[i]) {
                count++, i++;
            }
        }
        return count;
    }
};