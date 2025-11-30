class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] < nums[mid + 1])
                start = mid + 1;//go towards increasing slope where peak is present 
            else
                end = mid;//go towards decresasing slo[e -left side  
        }

        return start;
    }
};
