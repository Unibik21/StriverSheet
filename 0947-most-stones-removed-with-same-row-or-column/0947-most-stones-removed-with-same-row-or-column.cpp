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
    int removeStones(vector<vector<int>>& stones) {
        int maxR =-1;
        int maxC =-1;

        for(auto &it:stones){
            int x = it[0];
            int y = it[1];

            maxR = max(maxR,x);
            maxC = max(maxC,y);
        }

        DSU ds(maxR+maxC+2);
        unordered_set<int>st;
        for(auto &it:stones){
            int x= it[0];
            int y = it[1];

            int r = x;
            int c = maxR+1+y;
            st.insert(r);
            st.insert(c);
            ds.unionBySize(r,c);
        }
        int cnt =0;
        for(int i:st){
            if(i==ds.findParent(i))cnt++;
        }
        return stones.size()-cnt;
    }
};