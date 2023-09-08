class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>v(1,1);
        ans.push_back(v);
        for(int i=1;i<n;i++){
            vector<int>vv(i+1,1);
            for(int j=1;j<v.size();j++){
                vv[j]=v[j]+v[j-1];
            }
            v = vv;
            ans.push_back(v);
        }
        return ans;
    }
};