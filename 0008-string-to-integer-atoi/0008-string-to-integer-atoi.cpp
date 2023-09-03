class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '-') sign = -sign;
        if (str[i] == '-' || str[i] == '+') i++;
        
        while (str[i] >= '0' && str[i] <= '9'){
            int x =str[i++] - '0';

            if ((base>INT_MAX/10) || (base==INT_MAX/10 && x>7)){
                return sign==1?INT_MAX:INT_MIN;
            }
            base = 10 * base + x;
        }
        return base * sign;
    }
};