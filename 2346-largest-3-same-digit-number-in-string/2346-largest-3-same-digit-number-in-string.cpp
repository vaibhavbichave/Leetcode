class Solution {
public:
    string largestGoodInteger(string num) {
        string s;
        for (int i = 2; i < num.size(); i++) {
            string str = num.substr(i - 2, 3);
            if (num[i - 2] == num[i - 1] && num[i - 1] == num[i] && s < str)
                s = str;
        }
        return s;
    }
};