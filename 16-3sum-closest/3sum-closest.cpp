class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int bestDiff = INT_MAX;//isse minimum difference matlab closest element mil jaayega
        int ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int currSum = nums[i] + nums[l] + nums[r];
                int diff = abs(currSum - target);//positive kar deta hai 

                if (diff < bestDiff) {
                    bestDiff = diff;
                    ans = currSum;//final answer ans me stored hai isliye
                }

                if (currSum < target) {
                    l++;
                }
                else if (currSum > target) {
                    r--;
                }
                else {
                    return target;  // exact match
                }
            }
        }
        return ans;
    }
};
