class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto &j:adj[node]){
            if(!vis[j]){
                dfs(j,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>adj[isConnected.size()];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    int u = i;
                    int v = j;

                    adj[v].push_back(u);
                    adj[u].push_back(v);
                }
            }
        }

        vector<int>vis(isConnected.size(),0);
        int cnt =0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }

        return cnt;
    }
};