class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for (int curr = 0; curr < n; curr++) {
            int current = asteroids[curr];
            bool alive = true;

            while (!st.empty() && st.top() > 0 && current < 0) {

                if (abs(st.top()) < abs(current)) {
                    // Top asteroid explodes
                    st.pop();
                }
                else if (abs(st.top()) == abs(current)) {
                    // Both explode
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    // Current asteroid explodes
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(current);
            }
        }

        // Stack gives reverse order, so restore original order
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};