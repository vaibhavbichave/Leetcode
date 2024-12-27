class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size();) {
            if (i + 1 == s.size() && s[i] == '1')
                return count;
            if (s[i] == '0') {
                i++;
            } else {
                s[i] = '0';
                int carry = 1;
                for (int j = i + 1; j < s.size(); j++) {
                    if (carry) {
                        if (s[j] == '0') {
                            s[j] = '1';
                            carry = 0;
                            break;
                        } else {
                            s[j] = '0';
                        }
                    }
                }
                if (carry) s.push_back('1');
            }
            count++;
        }
        return count;
    }
};