/*Simple Algorithm

Compute totalSum

Set leftSum = 0

Loop i from 0 → n-1

Check:

if (leftSum == totalSum - leftSum - nums[i])
    return i


Update:

leftSum += nums[i]


If none found → return -1*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i])
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};
