class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>finalans;
        int left,right;
        //val1=i;val2=j
        int i=0;
        int j=i+1;
        for(i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(j=i+1;j<nums.size();j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                continue;
                left=j+1;
                right=nums.size()-1;
                while(left<right)
                {
                    long long reqtarget=(long long)target-nums[i]-nums[j];
                    long long sum=(long long)nums[left]+nums[right];
                    if(sum==reqtarget){
                    finalans.push_back({nums[left],nums[right],nums[i],nums[j]});
                    left++;
                    right--;
                    //validity
                    while (left < right && nums[left] == nums[left - 1])
                    left++;
                    while (left < right && nums[right] == nums[right + 1])
                    right--;
                    }
                    else if(sum<reqtarget)  
                   {
                    left++;
                    }         
                    else
                   right--;

                }
            }
        }return finalans;
    }
};