class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int& x : arr) {
            x = x & 1;
        }
        for (int i = 2; i < n; i++) {
            if (arr[i] && arr[i - 1] && arr[i - 2]) {
                return true;
            }
        }
        return false;
    }
};