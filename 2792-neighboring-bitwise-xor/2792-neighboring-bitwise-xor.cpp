class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result = 0;
        for (int num : derived)
            result ^= num;
        return result == 0;
    }
};