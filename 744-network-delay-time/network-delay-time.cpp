/*
------------------ Network Delay Time ------------------

1. Nodes are 1-based
   adj(n)  --->  adj(n + 1)

2. Distance array is also 1-based
   dist(n) ---> dist(n + 1)

3. Graph is Directed
   Only:
       adj[u].push_back({v, wt});
   Don't add:
       adj[v].push_back({u, wt});

4. Source node is given as 'k'
   Instead of:
       dist[src] = 0;
       pq.push({0, src});

   Use:
       dist[k] = 0;
       pq.push({0, k});

5. Return Value
   Don't return dist[]

   After Dijkstra:
   - If any node has INT_MAX -> return -1
   - Else return the maximum distance

6. Final loop
   for(int i = 1; i <= n; i++)
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        // Step 1: Adjacency List
        // {neighbour, weight}
        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            // Directed Graph
            adj[u].push_back({v, wt});
        }

        // Step 2: Distance Array
        vector<int> dist(n + 1, INT_MAX);

        // Step 3: Min Heap -> {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Source node
        dist[k] = 0;
        pq.push({0, k});

        // Step 4: Dijkstra
        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            // Ignore stale entry
            if(d > dist[node])
                continue;

            // Visit neighbours
            for(int j = 0; j < adj[node].size(); j++)
            {
                int neigh = adj[node][j].first;
                int weight = adj[node][j].second;

                // Relaxation
                if(d + weight < dist[neigh])
                {
                    dist[neigh] = d + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        // Step 5: Find maximum distance
        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            // If any node is unreachable
            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
