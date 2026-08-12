class Solution {
public:

    vector<int> parent;

    // Find root
    int find(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Merge two components
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(a != b)
            parent[b] = a;
    }

    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();

        parent.resize(n);

        // Initialize parent
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        // Store all possible edges
        vector<vector<int>> edges;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Manhattan distance
                int cost = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({i, j, cost});
            }
        }

        // Sort edges by cost
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b)
             {
                 return a[2] < b[2];
             });

        int totalCost = 0;
        int edgesTaken = 0;

        // Kruskal's Algorithm
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            int rootU = find(u);
            int rootV = find(v);

            // Different components -> take edge
            if(rootU != rootV)
            {
                totalCost += cost;
                unite(u, v);
                edgesTaken++;
            }

            // MST complete
            if(edgesTaken == n - 1)
                break;
        }

        return totalCost;
    }
};