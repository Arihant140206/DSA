class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int count=0;
        int maxcount=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==1)
            //if condition saties
                count++;
            else
            count=0;
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};