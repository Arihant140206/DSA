class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = 0;

        // Step 1: Move non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZero] = nums[i];
                nonZero++;
            }
        }

        // Step 2: Fill remaining positions with 0
        for (int i = nonZero; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
