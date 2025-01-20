class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m = houses.size(), n = heaters.size();
        vector<int> check(m, INT_MAX);
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0, j = 0; i < m && j < n;) {
            if (houses[i] <= heaters[j]) {
                check[i] = min(check[i], heaters[j] - houses[i]);
                i++;
            } else {
                j++;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0;) {
            if (houses[i] >= heaters[j]) {
                check[i] = min(check[i], houses[i] - heaters[j]);
                i--;
            } else {
                j--;
            }
        }
        return *max_element(check.begin(), check.end());
    }
};