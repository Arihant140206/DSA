class Solution {
public://SAME CODE AS AGGRESSIVE COWS IN GFG AND NOTESS
    bool isPossible(vector<int>& position, int m, int mid) {
        int left = 0;
        int count = 1;

        for(int right = 1; right < position.size(); right++) {
            if(position[right] - position[left] >= mid) {
                count++;
                left = right;
            }
        }

        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n = position.size();
        int left = 1;
        int right = position[n-1] - position[0];
        int ans = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(isPossible(position, m, mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};