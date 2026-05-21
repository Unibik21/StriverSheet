class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9+7;
        vector<long long>ways(n,0);
        vector<long long>time(n,LLONG_MAX);
        vector<pair<long long,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            long long t = roads[i][2];

            adj[u].push_back({t,v});
            adj[v].push_back({t,u});
        }
        time[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [t1,node] = pq.top();
            pq.pop();

            for(auto &j:adj[node]){
                int adjNode = j.second;
                long long t2 = j.first;

                if(time[adjNode]>t1+t2){
                    time[adjNode]=t1+t2;
                    ways[adjNode]=ways[node];
                    pq.push({time[adjNode],adjNode});
                }
                else if(time[adjNode]==t1+t2){
                    ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                }
            }
        }

        return ways[n-1];

    }
};