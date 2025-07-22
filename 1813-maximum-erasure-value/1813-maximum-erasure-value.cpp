class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, maxi = 0;
        unordered_map<int, int> mp;
        for (int i = 0, j = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];
            while (mp[nums[i]] > 1) {
                sum -= nums[j];
                mp[nums[j++]]--;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};