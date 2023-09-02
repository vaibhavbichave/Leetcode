class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
          if (seen.find(nums[i]) != seen.end()) {
            return {seen[nums[i]], i};
          } else {
            seen[target - nums[i]] = i;
          }
        }
        return {-1, -1}; 
    }
};