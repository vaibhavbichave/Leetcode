class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n - 2; k++) {
            int i = k + 1, j = n - 1;
            while (i < j) {
                int total = nums[i] + nums[j] + nums[k];
                if (total < 0) i++;
                else if (total > 0) j--;
                else st.insert({nums[i++], nums[j--], nums[k]});
            }
        }
        vector<vector<int>> v;
        for (auto x : st)
            v.push_back(x);
        return v;
    }
};