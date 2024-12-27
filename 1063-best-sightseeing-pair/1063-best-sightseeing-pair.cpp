class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int result = INT_MIN, sum = values[0];
        for (int i = 1; i < n; i++) {
            result = max(result, sum + values[i] - i);
            sum = max(sum, values[i] + i);
        }
        return result;
    }
};