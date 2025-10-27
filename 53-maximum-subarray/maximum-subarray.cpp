class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
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
    
};