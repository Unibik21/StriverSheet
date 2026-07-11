class Solution {
public:
    class DSU{
        public:
            vector<int>parent;
            vector<int>size;

            DSU(int n){
                parent.resize(n);
                size.resize(n,1);

                for(int i=0;i<n;i++)parent[i]=i;    
            }

            int findPar(int node){
                if(node==parent[node])return node;
                return parent[node]=findPar(parent[node]);
            }

            void unionBySize(int u,int v){
                int pu=findPar(u);
                int pv = findPar(v);

                if(pu==pv)return;

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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU ds(n);

        unordered_map<int,int>edgecnt;
        unordered_map<int,int>nodecnt;

        for(auto &e:edges){
            ds.unionBySize(e[0],e[1]);
        }

        for(int i=0;i<n;i++){
            nodecnt[ds.findPar(i)]++;
        }

        for(auto &e:edges){
            edgecnt[ds.findPar(e[0])]++;
        }

        int ans =0;

        for(auto &i:nodecnt){
            int node = i.second;
            int edge = edgecnt[i.first];

            if(edge== (node*(node-1))/2)ans++;
        }


        return ans;
    }
};