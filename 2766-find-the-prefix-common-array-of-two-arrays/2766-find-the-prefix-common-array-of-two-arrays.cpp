class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> result(n), frequency(n + 1, 0);
        for (int idx = 0; idx < n; ++idx) {
            if (++frequency[A[idx]] == 2) ++count;
            if (++frequency[B[idx]] == 2) ++count;
            result[idx] = count;
        }
        return result;
    }
};