class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int start=0,end=0,pro=1,count=0,n=nums.size();
       while(end<n){
        pro*=nums[end];
        while(start<=end&&pro>=k)
        {
            pro/=nums[start];
            start++;

        }
        count+=(end-start)+1;
        end++;
       } return count;
    }
};