class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> firstMap, secondMap;
        for (auto& num : nums) 
            secondMap[num]++;
        for (int index = 0; index < n; index++) {
            int num = nums[index];
            secondMap[num]--;
            firstMap[num]++;
            if (firstMap[num] * 2 > index + 1 &&
                secondMap[num] * 2 > n - index - 1) {
                return index;
            }
        }
        return -1;
    }
};