class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while(start < end) {
            int mid = start + (end - start) / 2;
//agar abhi ka element agle element se chota hai toh aage badho
            if(nums[mid] < nums[mid + 1])
                start = mid + 1;
            else//abhi wala bada hai toh end ko udhar le aao , ho sakta hai peak ho hehe
                end = mid;
        }
//peak tab milega jabb start and end mil jaayenge 
        return end;
    }
};