class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;  // i points to the position to place next valid element

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];  // keep only non-val elements
                i++;
            }
        }

        return i;  // number of elements that are not equal to val
    }
};
