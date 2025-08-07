class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n; k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int i = k + 1, j = n - 1;
            while (i < j) {
                int total = nums[i] + nums[j] + nums[k];
                if (total < 0) i++;
                else if (total > 0) j--;
                else {
                    v.push_back({nums[i++], nums[j--], nums[k]});
                    while (i < j && nums[i] == nums[i - 1]) i++;
                }
            }
        }
        return v;
    }
};