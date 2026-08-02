class Solution {
public:

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int n, int m, int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> height(n, vector<int>(m, -1));

        // Push all water cells[only difference in code is here]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }

        // Multi-Source BFS
        while (!q.empty()) {

            pair<int, int> p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            for (int k = 0; k < 4; k++) {

                int nr = r + x[k];
                int nc = c + y[k];

                if (valid(n, m, nr, nc) && height[nr][nc] == -1) {

                    height[nr][nc] = height[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return height;
    }
};