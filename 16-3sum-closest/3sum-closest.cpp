class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindiff=INT_MAX;
        int ans;
        sort(nums.begin(),nums.end());
        vector<vector<int>>finalans;
        int left,right;
        int i=0;
        for(i=0;i<nums.size();i++){
        left=i+1;
        right=nums.size()-1;
        
        while(left<right)
        {
            int sum=nums[i]+nums[left]+nums[right];
            int diff=abs(sum-target);
            if(diff<mindiff)
            {
                mindiff=diff;
                ans=sum;
            }
            if(sum==target)
            return sum;
            else if(sum<target)
            left++;
            else
            right--;
        }
    }return ans;
    }
};