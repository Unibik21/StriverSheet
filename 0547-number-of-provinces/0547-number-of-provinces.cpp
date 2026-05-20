class Solution {
public:
    void bfs(int node,vector<int>&vis,vector<int>adj[]){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
           int n = q.front();
           q.pop();
           for(auto &i:adj[n]){
            if(!vis[i]){q.push(i); vis[i]=1;}
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
                bfs(i,vis,adj);
                cnt++;
            }
        }

        return cnt;
    }
};