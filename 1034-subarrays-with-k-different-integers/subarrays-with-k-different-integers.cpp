class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //Exactly K = AtMost K − AtMost (K − 1),thodsa confusing hai understand from gpt
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int start = 0, count = 0;

        for (int end = 0; end < nums.size(); end++) {
            m[nums[end]]++;

            while (m.size() > k) {
                m[nums[start]]--;
                if (m[nums[start]] == 0)
                    m.erase(nums[start]);
                start++;
            }

            count += (end - start + 1);
        }
        return count;
    }
};
