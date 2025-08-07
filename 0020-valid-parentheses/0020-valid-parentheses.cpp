class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (char x : str) {
            if (x == '(' || x == '{' || x == '[') {
                s.push(x);
            } else {
                if (s.empty()) return false;
                else if (x == ')' && s.top() == '(') s.pop();
                else if (x == '}' && s.top() == '{') s.pop();
                else if (x == ']' && s.top() == '[') s.pop();
                else return false;
            }
        }
        return s.empty();
    }
};
