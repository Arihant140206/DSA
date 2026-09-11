/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];//imp
        int currentsum=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
        currentsum+=nums[i];

        if(currentsum>maxsum)
        maxsum=currentsum;
        if(currentsum<0)
        currentsum=0;
    }
        return maxsum;

    }
    
};*/

class Solution {
public:
    
    // recursive function
    int solve(vector<int>& nums, int i, int currentSum, int maxSum) {
        
        // base case
        if(i==nums.size())
        return maxSum;
        
        // process current element (update currentSum)
        currentSum=max(nums[i],currentSum+nums[i]);
        
        // update maxSum
        maxSum=max(maxSum,currentSum);
        
        // recursive call (move to next index)
        return solve(nums,i+1,currentSum,maxSum);
    }

    int maxSubArray(vector<int>& nums) {
        
        // initial call with:
        // index = 0
        // currentSum = ?
        // maxSum = ?
        return solve(nums,0,0,nums[0]);
        
    }
};