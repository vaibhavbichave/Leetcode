class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            int divisors = 0, sum = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    sum += i;
                    divisors++;
                    if (i * i != num) {
                        sum += num / i;
                        divisors++;
                    }
                }
            }
            result += (divisors == 4) ? sum : 0;
        }
        return result;
    }
};