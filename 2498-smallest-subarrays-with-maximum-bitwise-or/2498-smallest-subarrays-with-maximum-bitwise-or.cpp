class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), position(32, 0);
        for (int i = n - 1; i >= 0; i--) {
            int maxi = i;
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j))
                    position[j] = i;
                else
                    maxi = max(maxi, position[j]);
            }
            ans[i] = maxi - i + 1;
        }
        return ans;
    }
};