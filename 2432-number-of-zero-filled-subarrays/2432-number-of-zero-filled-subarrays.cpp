class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0, count = 0;
        for (int x : nums) {
            count = (x == 0) ? count + 1 : 0;
            sum += count;
        }
        return sum;
    }
};