class Solution {
    //basically gfg ka allocate pages wala exact qn hai ye
public:
    bool isPossible(vector<int>& weights, int days,long long mid)
    {
        long long currentweight=0;
        int currdays=1;
        for(int i=0;i<weights.size();i++){
            if(currentweight+weights[i]<=mid)
            currentweight+=weights[i];
            else
            {
                currdays++;
                currentweight=weights[i];
            }
        }
        return currdays<=days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        if(days>weights.size())
        return -1;
        long long sum=0;
        long long l=*max_element(weights.begin(),weights.end());
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        long long r=sum;
        long long ans =sum;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if(isPossible(weights,days,mid))
            {
                ans=mid;
                r=mid-1;
            }else
            l=mid+1;
        }return ans;
    }
};