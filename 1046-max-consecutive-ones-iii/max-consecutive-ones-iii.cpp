
        /*Problem in Simple Words

You have:

an array of 0s and 1s

you can flip at most k zeros → 1

Find the longest continuous stretch of 1s you can get.

Key Idea 🧠

Instead of actually flipping, we pretend we flipped.

We maintain a window that contains:

at most k zeros

If zeros exceed k, we shrink the window from the left.*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0, right = 0, maxlen = 0, zerocount = 0;
        int n = nums.size();

        for (right = 0; right < n; right++) {

            if (nums[right] == 0)
                zerocount++;

            while (zerocount > k) {
                if (nums[left] == 0)
                    zerocount--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
