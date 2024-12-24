class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            long long mid = (left + right) / 2, count = 0;
            for (int x : nums) {
                count += (x - 1) / mid;
                if (count > maxOperations) break;
            }
            if (count <= maxOperations) right = mid;
            else left = mid + 1;
        }

        return right;
    }
};