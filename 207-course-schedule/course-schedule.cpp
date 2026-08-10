class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        // Build graph
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];

            // dest -> src
            adj[dest].push_back(src);
            indeg[src]++;
        }

        queue<int> q;

        // Nodes with 0 indegree
        for(int i = 0; i < n; i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;

        // Kahn's Algorithm
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            count++;

            for(int j = 0; j < adj[node].size(); j++)
            {
                int neigh = adj[node][j];

                indeg[neigh]--;

                if(indeg[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }

        return count == n;
    }
};