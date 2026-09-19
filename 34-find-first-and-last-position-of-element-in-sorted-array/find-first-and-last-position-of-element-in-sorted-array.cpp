class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int ans1 = -1;
        int ans2 = -1;

        // Find FIRST occurrence
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ans1 = mid;
                r = mid - 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        // Reset
        l = 0;
        r = nums.size() - 1;

        // Find LAST occurrence
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ans2 = mid;
                l = mid + 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return {ans1, ans2};
    }
};