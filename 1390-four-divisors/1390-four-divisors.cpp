class Solution {
public:
    int getSumIfExactlyFourDivisors(int num) {
        int divisors = 0, sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                divisors++;
                if (i * i != num) {
                    sum += num / i;
                    divisors++;
                }
                if (divisors > 4) {
                    return 0;
                }
            }
        }
        return (divisors == 4) ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int num : nums)
            result += getSumIfExactlyFourDivisors(num);
        return result;
    }
};