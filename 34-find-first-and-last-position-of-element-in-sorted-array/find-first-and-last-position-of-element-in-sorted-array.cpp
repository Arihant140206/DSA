class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int first = -1, last = -1, mid;

        // Find first occurrence
        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == target) {
                first = mid;       // store position
                end = mid - 1;     // keep searching left
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        start = 0, end = nums.size() - 1;

        // Find last occurrence
        while (start <= end) {
            mid = (start + end) / 2;

            if (nums[mid] == target) {
                last = mid;        // store position
                start = mid + 1;   // keep searching right
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return {first, last};
    }
};
