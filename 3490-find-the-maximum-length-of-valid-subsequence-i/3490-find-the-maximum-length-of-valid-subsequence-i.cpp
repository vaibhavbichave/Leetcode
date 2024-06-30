class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> count(2), end(2);
        for (int a : nums) {
            count[a & 1]++;
            end[a & 1] = max(end[a & 1], end[1 - a & 1] + 1);
        }
        return max({count[0], count[1], end[0], end[1]});
    }
};