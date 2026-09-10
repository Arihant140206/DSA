class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixsum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];
            int rem=prefixsum%k;
            //check if rem exists in hashmap already and if yes check if size if size is greater than 2
            if(mp.find(rem)!=mp.end())
            {
                if(i-mp[rem]>=2)
                return true;
            }else{//store rem in hashma if already dosent exist
                mp[rem]=i;
            }
        }return false;
    }
};