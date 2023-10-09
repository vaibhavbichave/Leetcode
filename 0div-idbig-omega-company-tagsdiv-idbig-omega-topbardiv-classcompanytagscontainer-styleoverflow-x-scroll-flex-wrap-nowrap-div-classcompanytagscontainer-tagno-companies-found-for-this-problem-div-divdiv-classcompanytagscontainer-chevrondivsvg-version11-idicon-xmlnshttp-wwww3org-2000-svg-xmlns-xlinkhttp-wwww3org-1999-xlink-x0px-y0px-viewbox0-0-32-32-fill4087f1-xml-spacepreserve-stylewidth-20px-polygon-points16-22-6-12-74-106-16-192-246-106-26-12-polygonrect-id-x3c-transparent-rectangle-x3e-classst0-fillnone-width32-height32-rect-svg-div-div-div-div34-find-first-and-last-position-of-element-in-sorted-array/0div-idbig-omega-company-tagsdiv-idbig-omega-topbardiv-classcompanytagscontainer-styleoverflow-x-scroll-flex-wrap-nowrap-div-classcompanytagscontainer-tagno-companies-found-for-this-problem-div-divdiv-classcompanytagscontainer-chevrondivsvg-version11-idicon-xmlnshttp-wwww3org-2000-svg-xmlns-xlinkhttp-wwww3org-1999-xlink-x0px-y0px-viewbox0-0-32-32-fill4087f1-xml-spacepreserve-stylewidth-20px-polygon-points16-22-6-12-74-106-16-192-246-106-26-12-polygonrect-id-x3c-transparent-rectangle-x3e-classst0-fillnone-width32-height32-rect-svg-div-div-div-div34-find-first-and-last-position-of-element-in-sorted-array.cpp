class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = BinarySearch(nums, target, true);
        int rightIndex = BinarySearch(nums, target, false);

        if (leftIndex <= rightIndex) {
            return { leftIndex, rightIndex };
        } 
        return { -1, -1 };
    }

    int BinarySearch(vector<int>& nums, int target, bool findLeft) {
        int low = 0;
        int high = nums.size() - 1;
        int index = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else {
                index = mid;
                if (findLeft) high = mid - 1;
                else low = mid + 1; 
            }  
        }
        return index;
    }
};