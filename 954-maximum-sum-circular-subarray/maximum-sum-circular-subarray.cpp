class Solution {
public://do after qn 1749 , par is qn me abs ka koi jhamela nahi hai ,bas positive maxsubarraysum find karna hai , jo ya tioh normally milega ya end me lastke+start ke terms add karke milega as its a circular array .
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int max_end = 0, max_sum = INT_MIN;
        int min_end = 0, min_sum = INT_MAX;

        for (int x : nums) {
            totalSum += x;//total sum of all elements

            // Maximum subarray sum
            max_end = max(x, max_end + x);
            max_sum = max(max_sum, max_end);

            // Minimum subarray sum(we subtract this later from total sum to fing other )
            min_end = min(x, min_end + x);
            min_sum = min(min_sum, min_end);
        }

        // All numbers are negative(edge case) taaki final answer me negative answer na rahe 
        if (max_sum < 0)
            return max_sum;
//ya toh beech ka maxsum ya bacha hua ending and start ka part
        return max(max_sum, totalSum - min_sum);
    }
};
