class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atleast(k, word) - atleast(k + 1, word);
    }
    long long atleast(int k, string word) {
        unordered_map<char, int> freq;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        long long  count = 0, consonants = 0, left = 0, n = word.size();
        for (int right = 0; right < n; right++) {
            char character = word[right];
            freq[character]++;
            if (vowels.find(character) == vowels.end())
                consonants++;
            while (consonants >= k && hasAllVowels(freq)) {
                count += (n - right);
                char leftChar = word[left];
                if (vowels.find(leftChar) == vowels.end())
                    consonants--;
                if (--freq[leftChar] == 0)
                    freq.erase(leftChar);
                left++;
            }
        }
        return count;
    }

    bool hasAllVowels(unordered_map<char, int>& freq) {
        return freq['a'] > 0 && freq['e'] > 0 && freq['i'] > 0 &&
               freq['o'] > 0 && freq['u'] > 0;
    }
};