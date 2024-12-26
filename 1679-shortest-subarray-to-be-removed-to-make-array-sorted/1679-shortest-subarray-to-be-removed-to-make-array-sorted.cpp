class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left + 1 < n && arr[left] <= arr[left + 1])
            left++;
        while (right > 0 && arr[right - 1] <= arr[right])
            right--;
        if (left >= right) return 0;
        int result = min(n - left - 1, right);
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) i++;
            else j++;
            result = min(result, j - i);
        }
        return result;
    }
};