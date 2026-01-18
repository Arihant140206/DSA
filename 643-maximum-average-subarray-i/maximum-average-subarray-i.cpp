class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //maxAverage hume basically maximum sum ka average find karne bol raha hai
        int n =nums.size();
        if(k>n)
        return 0;
        int windowsum=0;
        int maxsum=INT_MIN;

        //first window sum
        for(int i =0;i<k;i++){
            windowsum+=nums[i];
        }
        maxsum=windowsum;
        //other windows
        for(int i=k;i<n;i++){
            windowsum+=nums[i]-nums[i-k];
            maxsum=max(maxsum,windowsum);
        }return (double)maxsum/k;
    }
};