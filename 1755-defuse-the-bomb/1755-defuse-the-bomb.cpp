class Solution {
public:
    vector<int> helper(vector<int>& code, int k) {
        long long n = code.size(), sum = 0;
        vector<int> v(n, 0);
        for (int i = 0; i < k; i++)
            sum += code[i];
        for (int i = 0; i < n; i++) {
            int index = (i + k) % n;
            sum += code[index] - code[i];
            v[i] = sum;
        }
        return v;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        if (k >= 0) {
            return helper(code, k);
        }
        reverse(code.begin(), code.end());
        auto v = helper(code, -k);
        reverse(v.begin(), v.end());
        return v;
    }
};