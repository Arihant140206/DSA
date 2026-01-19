class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //thoda sa complex hai par baar aar revise karke ho jaayega 
        unordered_map<int,int>mp;
        int zero=0,one=0,maxlen=0;
        mp[0]=-1;//base case
        //frequency count of one and zeros
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0)
                zero++;
                else
                one++;
           int diff=one-zero;

           if(mp.count(diff)){
            maxlen=max(maxlen,i-mp[diff]);

           }else{
            mp[diff]=i;
           } 
        }return maxlen;
    }
};