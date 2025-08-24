class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x, ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;  // use long long to avoid overflow

            if (mid * mid == x) {
                return mid;  // exact square root
            }
            else if (mid * mid < x) {
                ans = mid;      // store the floor value
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;  // return floor(sqrt(x))
    }
};
