class Solution {
public:
    vector<int> sieve(int lowerLimit, int upperLimit) {
        vector<int> primeNumbers;
        vector<int> sieve(upperLimit + 1, 1);
        sieve[0] = 0, sieve[1] = 0;
        for (int number = 2; number * number <= upperLimit; number++) {
            if (sieve[number] == 1) {
                for (int multiple = number * number; multiple <= upperLimit;
                     multiple += number) {
                    sieve[multiple] = 0;
                }
            }
        }
        for (int number = lowerLimit; number <= upperLimit; number++) {
            if (sieve[number] == 1) {
                primeNumbers.push_back(number);
            }
        }
        return primeNumbers;
    }

    vector<int> closestPrimes(int left, int right) {
        int minDifference = INT_MAX;
        vector<int> primeNumbers = sieve(left, right);
        if (primeNumbers.size() < 2)
            return vector<int>{-1, -1};
        vector<int> closestPair(2, -1);
        for (int index = 1; index < primeNumbers.size(); index++) {
            int difference = primeNumbers[index] - primeNumbers[index - 1];
            if (difference < minDifference) {
                minDifference = difference;
                closestPair[0] = primeNumbers[index - 1];
                closestPair[1] = primeNumbers[index];
            }
        }
        return closestPair;
    }
};