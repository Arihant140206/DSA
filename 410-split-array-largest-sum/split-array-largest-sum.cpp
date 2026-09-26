class Solution {
public://literally same as allocate pages in gfg

    bool isPossible(vector<int>& nums, int k, long long mid) {

        // 1. Current subarray ka sum track karne ke liye variable banao
        long long sum=0;

        // 2. Abhi tak kitne subarrays banaye hain, usko count karo
        int subarrcount=1;//initial subarr like studnets=1
        // 3. Array traverse karo
        //    Agar currentSum + nums[i] <= mid:
        //        nums[i] ko current subarray mein add karo
        for(int i=0;i<nums.size();i++)
        {
            if(sum + nums[i] <= mid)
            sum+=nums[i];
            else{
            subarrcount++;
            sum=nums[i];
            
            }
        }
        return subarrcount<=k;
        //    Otherwise:
        //        Naya subarray start karo
        //        currentSum = nums[i]
        //        subarray count badhao
       

        // 4. Finally check karo:
        //    kya subarrays <= k hain?
        //    YES → true
        //    NO  → false

    }


    int splitArray(vector<int>& nums, int k) {

        long long l = *max_element(nums.begin(), nums.end());

        long long r = 0;
        for (int x : nums) {
            r += x;
        }

        long long ans = r;

        while (l <= r) {

            long long mid = l + (r - l) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};