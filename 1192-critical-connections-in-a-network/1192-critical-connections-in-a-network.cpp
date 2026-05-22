class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int>&low,vector<int>&tv,vector<int>&vis,vector<vector<int>>&bridge,vector<int>adj[]){
        tv[node]=timer;
        low[node]=timer;
        vis[node]=1;
        timer++;
        for(auto &it:adj[node]){
            int adjNode = it;
            if(adjNode==parent)continue;
            if(!vis[adjNode]){
                dfs(adjNode,node,low,tv,vis,bridge,adj);
                low[node]=min(low[node],low[adjNode]);
                if(tv[node]<low[adjNode])bridge.push_back({node,adjNode});
            }
            else{
                low[node]=min(low[node],low[adjNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto &i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>tv(n);
        vector<int>low(n);
        vector<int>vis(n,0);
        vector<vector<int>>bridge;

        dfs(0,-1,tv,low,vis,bridge,adj);
        return bridge;
    }
};