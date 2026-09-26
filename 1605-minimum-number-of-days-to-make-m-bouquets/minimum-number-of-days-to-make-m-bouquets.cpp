class Solution {
public:

    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {

        // 1. Consecutive bloomed flowers ko track karne ke liye variable banao
        int cons=0;//consecutive
        int bouquets=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            cons++;
            else
            cons=0;
            if(cons==k)
            {
                bouquets++;
                cons=0;
            }
        }
            return bouquets>=m;
        
    }
        // 2. Ban chuke bouquets ko count karne ke liye variable banao


        // 3. Array ko traverse karo
        //    Agar bloomDay[i] <= mid:
        //        flower bloom ho chuka hai
        //        consecutive count badhao
        //
        //    Otherwise:
        //        consecutive count ko 0 karo


        // 4. Agar consecutive flowers == k:
        //        ek bouquet ban gaya
        //        bouquets count badhao
        //        consecutive count reset karo


        // 5. Finally check karo:
        //    kya bouquets >= m hain?
        //    YES → true
        //    NO  → false

    


    int minDays(vector<int>& bloomDay, int m, int k) {

        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (isPossible(bloomDay, m, k, mid)) {
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