class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int i = 0, n = nums.size();
        vector<int> v;
        while (i < n) {
            int curr = nums[i];
            int sum = 0, add = curr ? 1 : -1;
            while (i < n && curr == nums[i])
                sum += add, i++;
            v.push_back(sum);
            maxi = sum > 0 ? max(maxi, sum) : maxi;
        }
        if (v.size() == 1 && nums[0] == 1)
            return maxi - 1;
        for (int i = 1; i < v.size() - 1; i++)
            maxi = (v[i] == -1) ? max(maxi, v[i - 1] + v[i + 1]) : maxi;
        return maxi;
    }
};