class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0, maxi = INT_MIN;
        for (int num : nums) {
            if (num > 0 && st.find(num) == st.end()) {
                sum += num;
                st.insert(num);
            }
            maxi = max(maxi, num);
        }
        return sum > 0 ? sum : maxi;
    }
};