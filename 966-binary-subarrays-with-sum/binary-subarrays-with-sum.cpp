class Solution {
public://literally same as basic 560 qn , same code prefix sum template
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int ans=0;
        long long prefix=0;
        unordered_map<long long,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            if(mp.count(prefix-k))
            {
                ans+=mp[prefix-k];
            }mp[prefix]++;
        }return ans;
    }
    
};