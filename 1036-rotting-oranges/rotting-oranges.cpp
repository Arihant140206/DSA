class Solution {
public:

    // 4 directions -> Up, Down, Left, Right
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    // Check if cell is inside the grid
    bool valid(int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;

        return true;
    }

    int orangesRotting(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;
        int time = 0;

        // Step 1: Put all rotten oranges in queue
        // Count fresh oranges
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 2)
                {
                    q.push({i, j});
                    a[i][j] = -2;   // Mark visited
                }
                else if(a[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // Step 2: Multi-source BFS
        while(!q.empty() && fresh > 0)
        {
            time++;

            int s = q.size();   // Current level

            while(s--)
            {
                pair<int,int> p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                // Check all 4 neighbours
                for(int k = 0; k < 4; k++)
                {
                    int row = r + x[k];
                    int col = c + y[k];

                    // Fresh orange found
                    if(valid(row, col, n, m) && a[row][col] == 1)
                    {
                        q.push({row, col});
                        a[row][col] = -2;   // Mark rotten
                        fresh--;
                    }
                }
            }
        }

        // Fresh oranges still left
        if(fresh > 0)
            return -1;

        return time;
    }
};