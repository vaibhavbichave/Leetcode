class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>v;
        map<int,vector<int>>mp;
        for(int i=0;i<groupSizes.size();i++) mp[groupSizes[i]].push_back(i);
        for(auto x:mp){
            int n = x.second.size();
            for(int i=0;i<n/x.first;i++){
                vector<int>vv;
                for(int j=0;j<x.first;j++){
                    vv.push_back(x.second[j+(i/x.first)*x.first]);
                }
                v.push_back(vv);
            }
        }
        return v;
    }
};