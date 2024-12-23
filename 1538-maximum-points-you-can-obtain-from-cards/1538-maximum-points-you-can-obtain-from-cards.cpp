class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0, curr = 0, n = cardPoints.size();
        for (int x : cardPoints) total += x;
        for (int i = 0; i < n - k; i++) curr += cardPoints[i];
        int mini = curr;
        for (int i = n - k; i < n; i++) {
            curr += cardPoints[i] - cardPoints[i - n + k];
            mini = min(mini, curr);
        }
        return total - mini;
    }
};