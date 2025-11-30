class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // Make mid always point to even index
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1])
                s = mid + 2;   // pair is complete, go right
            else
                e = mid;       // broken pair, go left
        }

        return nums[s];
    }
};
