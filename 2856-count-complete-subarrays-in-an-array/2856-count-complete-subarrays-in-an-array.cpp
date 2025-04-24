class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0, n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        for (int j = 0; j < n; j++) {
            unordered_set<int> st1;
            for (int i = j; i < n; i++) {
                st1.insert(nums[i]);
                count += (st.size() == st1.size());
            }
        }
        return count;
    }
};