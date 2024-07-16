class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }
        int min1 = INT_MAX, max1 = INT_MIN;
        int min2 = INT_MAX, max2 = INT_MIN;
        int min3 = INT_MAX, max3 = INT_MIN;
        int min4 = INT_MAX, max4 = INT_MIN;
        for (int x : nums) {
            if (x < min1) {
                min4 = min3;
                min3 = min2;
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min4 = min3;
                min3 = min2;
                min2 = x;
            } else if (x < min3) {
                min4 = min3;
                min3 = x;
            } else if (x < min4) {
                min4 = x;
            }

            if (x > max1) {
                max4 = max3;
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max4 = max3;
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max4 = max3;
                max3 = x;
            } else if (x > max4) {
                max4 = x;
            }
        }

        vector<int> mini = {min1, min2, min3, min4};
        vector<int> maxi = {max1, max2, max3, max4};

        int result = INT_MAX;
        for (int i = 0; i < 4; i++) {
            result = min(result, maxi[3 - i] - mini[i]);
        }
        return result;
    }
};