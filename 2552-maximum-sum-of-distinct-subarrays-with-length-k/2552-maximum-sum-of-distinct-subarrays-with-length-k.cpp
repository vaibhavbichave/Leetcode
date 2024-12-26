class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, result = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }
        if (mp.size() == k)
            result = max(result, sum);
        for (int i = k; i < n; i++) {
            mp[nums[i]]++;
            mp[nums[i - k]]--;
            sum += (nums[i] - nums[i - k]);
            if (mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            if (mp.size() == k) result = max(result, sum);
        }
        return result;
    }
};