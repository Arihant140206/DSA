class Solution {
public:

    int countLessEqual(int m, int n, int mid) {
        int count = 0;

        for(int i = 1; i <= m; i++) {
            count += min(mid / i, n);
        }

        return count;
    }

    int findKthNumber(int m, int n, int k) {

        int left = 1;
        int right = m * n;
        int ans = -1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(countLessEqual(m, n, mid) >= k) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};