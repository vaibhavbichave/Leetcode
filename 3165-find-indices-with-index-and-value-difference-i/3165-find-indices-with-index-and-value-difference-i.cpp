class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDiff, int valueDiff) {
        int mini = 0, maxi = 0, n = nums.size();
        for (int i = indexDiff; i < n; i++) {
            if (nums[i - indexDiff] < nums[mini]) mini = i - indexDiff;
            if (nums[i - indexDiff] > nums[maxi]) maxi = i - indexDiff;
            if ((nums[i] - nums[mini]) >= valueDiff) return {mini, i};
            if ((nums[maxi] - nums[i]) >= valueDiff) return {maxi, i};
        }
        return {-1, -1};
    }
};