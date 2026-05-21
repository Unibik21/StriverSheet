class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adj[u].push_back({time,v});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &j:adj[node]){
                int edgetime = j.first;
                int next = j.second;
                if(time[next]>t+edgetime){
                    time[next]=t+edgetime;
                    pq.push({time[next],next});
                }
            }
        }

        int mini = -1;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX)return -1;
            mini =  max(mini,time[i]);
        }
        return mini;
    }
};