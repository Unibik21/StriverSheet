class Solution {
    bool dfs2(int node,vector<int>&vis,vector<vector<int>>&adj){
        for(auto &i:adj[node]){
            if(vis[i]==1){
                return true;
            }
        }

        return false;
    }
    void dfs1(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;

        for(auto &j:adj[node]){
            if(vis[j]==-1)dfs1(j,vis,adj);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto &i:invocations){
            int a = i[0];
            int b = i[1];

            adj[a].push_back(b);
        }
        vector<int>vis(n,-1);
        dfs1(k,vis,adj);

        bool a = false;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                a = true;
                break;
            }
        }
        if(!a){
            return {};
        }
        bool b = false;
        for(int i=0;i<n;i++){
            if(vis[i]==-1  && dfs2(i,vis,adj)){
                b = true;
                break;
            }
        }

        vector<int>ans;

        if(!b){
            for(int i=0;i<n;i++){
                if(vis[i]==-1)ans.push_back(i);
            }
        }
        else{
           for(int i=0;i<n;i++)ans.push_back(i);
        }

        return ans;
    }
};