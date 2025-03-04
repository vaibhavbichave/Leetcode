class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string result;
        int n = pattern.size();
        for (int i = 0; i <= n; i++) {
            st.push(i + 1);
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};