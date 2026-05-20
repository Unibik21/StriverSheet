class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&color){
        for(auto &j:graph[node]){
            if(color[j]==-1){
                color[j]=!color[node];
                if(!dfs(j,graph,color))return false;
            }
            else if(color[j]==color[node])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,color))return false;
            }
        }
        return true;
    }
};