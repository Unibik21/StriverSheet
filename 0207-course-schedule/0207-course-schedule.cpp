class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis){
        vis[node] = 1;
        pathvis[node]=1;

        for(auto &i:adj[node]){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis))return true;
            }
            if(pathvis[i])return true;
        }

        pathvis[node]=0;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int>vis(num,0);
        vector<int>pathvis(num,0);
        vector<int>adj[num];
        for(int i=0;i<pre.size();i++){
            int u = pre[i][1];
            int v = pre[i][0];

            adj[u].push_back(v);
        }

        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis))return false;
            }
        }

        return true;
    }
};