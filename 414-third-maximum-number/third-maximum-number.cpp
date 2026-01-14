class Solution {
public:
    int thirdMax(vector<int>& nums) {

        // make pq (minheap)
        priority_queue<int, vector<int>, greater<int>> p;

        // check for duplicates by traversing and making a duplicate of pq
        for (int x : nums) {

            bool duplicate = false;
            priority_queue<int, vector<int>, greater<int>> temp = p;

            while (!temp.empty()) {
                if (temp.top() == x) {
                    duplicate = true;
                    break;
                }
                temp.pop();
            }

            if (duplicate)
                continue;

            // building final ans
            p.push(x);

            // more than 3
            if (p.size() > 3)
                p.pop();
        }

        // less than 3 so we return max element present
        if (p.size() < 3) {
            while (p.size() > 1)
                p.pop();
        }

        return p.top();
    }
};
