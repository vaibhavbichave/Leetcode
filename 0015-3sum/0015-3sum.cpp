class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        set<vector<int>> st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int t=-nums[i];
            int s=i+1,e=n-1;
            while(s<e){
                int sum=nums[s]+nums[e];
                if (sum<t) s++;
                else if (sum>t) e--;
                else{
                    st.insert({nums[i],nums[s],nums[e]});
                    s++;e--;
                }
            }
        }
        for(auto i: st)
           res.push_back(i);
        return res;
    }
};