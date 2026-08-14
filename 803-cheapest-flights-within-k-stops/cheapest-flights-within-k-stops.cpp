class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int  INF=1e9;
        vector<int>dist(n,INF);
        dist[src]=0;

        for(int i=0;i<k+1;i++)
        {
            vector<int>temp=dist;
            for(auto flight:flights)
            {
                int u=flight[0];
                int v=flight[1];
                int price=flight[2];

                if(dist[u]!=INF)
                {
                    temp[v]=min(temp[v],dist[u]+price);
                }
            }
            dist=temp;
            
        }
        if(dist[dst]==INF)
            return -1;
            return dist[dst];
    }
};