class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v,cost});
        }

        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty() && k>=0){
            int size = q.size();
            for(int s=0;s<size;s++){
                auto it = q.front();
                q.pop();
                int node = it.first;
                int cost = it.second;

                for(auto &j:adj[node]){
                    int adjNode = j.first;
                    int edgeCost = j.second;
                    if(dist[adjNode]>edgeCost+cost){
                        dist[adjNode]=edgeCost+cost;
                        q.push({adjNode,dist[adjNode]});
                    }
                }
            }
            k--;
        }

        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];

    }
};