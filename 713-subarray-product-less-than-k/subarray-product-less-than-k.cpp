class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0,l=0;
        int r;
        int prod=1;
        for(r=0;r<nums.size();r++)
        {
            if(k<=1)
            return 0;
            prod*=nums[r];
            while(prod>=k)
            {
                prod/=nums[l];
                l++;
            }
            count += (r - l + 1);

        }return count;
    }
};