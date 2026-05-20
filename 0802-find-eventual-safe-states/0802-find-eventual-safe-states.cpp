class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ind(graph.size(),0);
        vector<int>adj[graph.size()];

        for(int i=0;i<graph.size();i++){
            for(auto &j: graph[i]){
                int u = j;
                int v = i;

                adj[u].push_back(v);
                ind[v]++;
            }
        }

        queue<int>q;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0)q.push(i);
        }
        
        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto&i:adj[node]){
                ind[i]--;
                if(ind[i]==0)q.push(i);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};