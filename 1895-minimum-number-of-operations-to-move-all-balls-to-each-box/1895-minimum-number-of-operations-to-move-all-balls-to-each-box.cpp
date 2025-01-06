class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), count = 0;
        vector<int> left(n, 0), right(n, 0), res(n, 0);
        for (int i = 1, count = 0; i < n; i++) {
            count += (boxes[i - 1] - '0');
            left[i] = left[i - 1] + count;
        }
        for (int i = n - 2, count = 0; i >= 0; i--) {
            count += (boxes[i + 1] - '0');
            right[i] = right[i + 1] + count;
        }
        for (int i = 0; i < n; i++)
            res[i] = left[i] + right[i];
        return res;
    }
};