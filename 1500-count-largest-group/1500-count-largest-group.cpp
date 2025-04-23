class Solution {
public:
    int countLargestGroup(int n) {
        int result = 0, maxi = 0;
        unordered_map<int, int> mp;
        for (int idx = 1; idx <= n; idx++) {
            int sum = 0, num = idx;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            mp[sum]++;
            maxi = max(maxi, mp[sum]);
        }
        for (auto [sum, count] : mp) {
            if (count == maxi) {
                result++;
            }
        }
        return result;
    }
};