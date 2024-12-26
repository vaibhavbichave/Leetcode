class Solution {
public:
    bool canDistribute(vector<int>& quantities, int target, int n) {
        long long stores = 0;
        for (int quantity : quantities) stores += (quantity + target - 1) / target;
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (canDistribute(quantities, middle, n)) right = middle;
            else left = middle + 1;
        }
        return right;
    }
};