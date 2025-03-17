class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) 
            counter[num]++;
        for (auto [x, count] : counter) 
            if (count & 1) 
                return false;
        return true;
    }
}; 