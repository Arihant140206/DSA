class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Max Heap (pair: frequency, element)
        priority_queue<pair<int, int>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        // Step 3: Extract top k
        vector<int> result;

        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};