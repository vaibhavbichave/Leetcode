class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> unique, prev;
        for (int i = 0; i < n; i++) {
            unordered_set<int> curr;
            curr.insert(arr[i]);
            unique.insert(arr[i]);
            for (int x : prev) {
                curr.insert(x | arr[i]);
                unique.insert(x | arr[i]);
            }
            prev = curr;
        }

        return unique.size();
    }
};