class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int>topo;
        vector<int>adj[num];
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];

            adj[u].push_back(v);
        }
        vector<int>ind(num,0);
        for(int i=0;i<num;i++){
            for(auto &it:adj[i]){
                ind[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<num;i++){
            if(ind[i]==0)q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto &it:adj[node]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
        }

        if(topo.size()==num)return topo;
        return {};
    }
};