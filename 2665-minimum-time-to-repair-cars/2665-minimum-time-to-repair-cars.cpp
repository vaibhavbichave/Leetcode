class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = LLONG_MAX, res = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2, k = 0;
            for (int rank : ranks) {
                k += sqrt(mid / rank);
                if (k >= cars) {
                    break;
                }
            }
            if (k >= cars) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};