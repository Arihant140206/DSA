class Solution {
public:

    bool res = true;

    // DFS Function
    void dfs(vector<vector<int>>& graph, int node, int color, vector<int>& colors)
    {
        // Current node ko current color de do
        colors[node] = color;

        // Current node ke saare neighbours check karo
        for(int j = 0; j < graph[node].size(); j++)
        {
            int neigh = graph[node][j];

            // CASE 1 : Neighbour pehle se visited hai
            if(colors[neigh] != -1)
            {
                // Agar neighbour ka color bhi same hai
                // to graph bipartite nahi ho sakta
                if(colors[neigh] == color)
                {
                    res = false;
                }
            }

            // CASE 2 : Neighbour visit nahi hua
            else
            {
                // Opposite color dekar DFS karo
                dfs(graph, neigh, 1 - color, colors);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();

        // -1 = Unvisited
        //  0 = Color A
        //  1 = Color B
        vector<int> colors(n, -1);

        // Har node check karenge
        // Kyunki graph disconnected bhi ho sakta hai
        for(int i = 0; i < n; i++)
        {
            // Agar node visit nahi hui
            if(colors[i] == -1)
            {
                // Is component ki starting color = 0
                dfs(graph, i, 0, colors);
            }
        }

        return res;
    }
};