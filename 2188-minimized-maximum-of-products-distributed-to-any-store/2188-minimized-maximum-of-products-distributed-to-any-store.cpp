class Solution {
public:
    bool canDistribute(int x, vector<int>& quantities, int n) {
        int j = 0, m = quantities.size();
        int remaining = quantities[j];
        for (int i = 0; i < n; i++) {
            if (remaining <= x && ++j) {
                if (j == m) return true;
                remaining = quantities[j];
            } else {
                remaining -= x;
            }
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 0, right = INT_MAX;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (canDistribute(middle, quantities, n)) right = middle;
            else left = middle + 1;
        }
        return right;
    }
};