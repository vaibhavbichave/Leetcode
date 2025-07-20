class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int prod = 1, sum = 0;
        while (n) {
            int digit = n % 10;
            prod *= digit;
            sum += digit;
            n /= 10;
        }
        return (temp % (sum + prod)) == 0;
    }
};