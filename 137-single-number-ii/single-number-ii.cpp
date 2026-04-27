class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int currbits=0,p=0,k=3;
        long ans=0;

        for(int i=0;i<32;i++){
            currbits=0;
            for(int j=0;j<n;j++){
                currbits+=(nums[j]&1);
                nums[j]=nums[j]>>1;
            }
            currbits=currbits%k;
            ans=ans+currbits*pow(2,p);
            p++;

        }return ans;
    }
};