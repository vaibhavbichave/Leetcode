class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) return false;
        int open_count = 0, close_count = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(') open_count++;
            else open_count--;
            if (open_count < 0) return false;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') close_count++;
            else close_count--;
            if (close_count < 0) return false;
        }
        return true;
    }
};