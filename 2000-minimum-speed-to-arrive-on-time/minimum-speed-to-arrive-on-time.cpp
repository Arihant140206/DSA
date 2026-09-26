class Solution {
public:

    bool isPossible(vector<int>& dist, double hour, int mid) {

        // 1. Ek totalTime variable banao
        //    → kyunki last train ka time decimal ho sakta hai
        int n=dist.size();
        double totaltime=0;
        double timeper=0;
        double lasttime=0;


        // 2. First n-1 trains ke liye loop chalao
        //    → har train ka travel time CEILING mein add karna hai
        //    → Koko wala (a + b - 1) / b formula yaad rakho
        for(int i=0;i<n-1;i++)
        {
            timeper=(dist[i]+mid-1)/mid;
            totaltime+=timeper;
        }


        // 3. Last train ka time EXACT calculate karo
        //    → isko ceil nahi karna
        //    → double division chahiye
        lasttime = (double)dist[n-1] / mid;
        totaltime+=lasttime;


        // 4. totalTime ko given 'hour' se compare karo
        //    → agar totalTime <= hour → possible
        //    → otherwise → not possible
        if(totaltime<=hour)
        {
            return true;
        }return false;


    }


    int minSpeedOnTime(vector<int>& dist, double hour) {

        int l = 1;
        int r = 10000000;
        int ans = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (isPossible(dist, hour, mid)) {
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