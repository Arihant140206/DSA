class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>finalans;
        int left,right;
        int val=0;
        for(val=0;val<nums.size();val++){
        if (val > 0 && nums[val] == nums[val - 1])
        continue;
        left=val+1;
        right=nums.size()-1;
        {
            while(left<right)
            {
                int target=-1*(nums[val]);
                int sum=nums[left]+nums[right];
                if(sum==target)
                {
                    finalans.push_back({nums[left], nums[right], nums[val]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                     left++;

                    while (left < right && nums[right] == nums[right + 1])
                     right--;
                    
                 }
                
                else if(sum<target)  
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