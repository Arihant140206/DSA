class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -DBL_MAX;
        int l = 0;
        int window = 0;

        for (int r = 0; r < nums.size(); r++) {
            window += nums[r];

            if (r - l + 1 > k) {
                window -= nums[l];
                l++;
            }

            if (r - l + 1 == k) {
                double avg = (double)window / k;
                ans = max(ans, avg);
            }
        }

        return ans;
    }
};