class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int node, vector<vector<int>>& graph)
    {
        // Current node ko path me add karo
        path.push_back(node);

        // Destination mil gaya
        if(node == graph.size() - 1)
        {
            ans.push_back(path);

            // Backtracking
            path.pop_back();
            return;
        }

        // Current node ke saare neighbours pe DFS
        for(int i = 0; i < graph[node].size(); i++)
        {
            int neigh = graph[node][i];

            dfs(neigh, graph);
        }

        // Backtracking
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        dfs(0, graph);

        return ans;
    }
};