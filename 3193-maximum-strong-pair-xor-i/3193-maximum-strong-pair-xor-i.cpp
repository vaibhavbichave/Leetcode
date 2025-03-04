class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxi = 0, n  = nums.size();
        for (int i = 0; i < n - 1; i++) 
            for (int j = i + 1; j < n; j++) 
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) 
                    maxi = max(nums[i] ^ nums[j], maxi);
        return maxi;
    }
};