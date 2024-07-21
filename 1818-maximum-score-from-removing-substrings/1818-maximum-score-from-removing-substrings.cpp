class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return max(helper(s, 'a', 'b', x, y), helper(s, 'b', 'a', y, x));
    }
    int helper(string& str, char first, char second, int a, int b) {
        int value = 0;
        string middle = helper2(str, first, second, a, value);
        string middl2 = helper2(middle, second, first, b, value);
        return value;
    }
    string helper2(string& str, char first, char second, int add, int& value) {
        string answer;
        for (char x : str) {
            if (x != second) {
                answer.push_back(x);
            } else {
                if (!answer.empty() && answer.back() == first) {
                    value += add;
                    answer.pop_back();
                } else {
                    answer.push_back(x);
                }
            }
        }
        return answer;
    }
};