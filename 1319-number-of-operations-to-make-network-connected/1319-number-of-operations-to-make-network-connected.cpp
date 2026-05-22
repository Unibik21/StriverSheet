class Solution {
    class DSU{
        vector<int>parent;
        vector<int>size;
        public:
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)parent[i]=i;
        }

        int findParent(int u){
            if(u==parent[u])return u;
            return parent[u]=findParent(parent[u]);
        }

        void unionBySize(int u,int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu==pv)return ;
            if(size[pu]>size[pv]){
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
            else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int total = connections.size();
        int available = 0;
        DSU ds(n);
        for(auto &it:connections){
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u)==ds.findParent(v)){
                available++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int comp = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i)comp++;
        }
        int need= comp-1;
        if(need>available)return -1;
        return need;
    }
};