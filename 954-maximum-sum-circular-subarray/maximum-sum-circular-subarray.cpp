class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int max_end = 0, max_sum = INT_MIN;
        int min_end = 0, min_sum = INT_MAX;

        for (int x : nums) {
            totalSum += x;

            // Maximum subarray sum
            max_end = max(x, max_end + x);
            max_sum = max(max_sum, max_end);

            // Minimum subarray sum
            min_end = min(x, min_end + x);
            min_sum = min(min_sum, min_end);
        }

        // All numbers are negative
        if (max_sum < 0)
            return max_sum;

        return max(max_sum, totalSum - min_sum);
    }
};
