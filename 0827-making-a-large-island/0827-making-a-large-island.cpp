class Solution {
    class DSU{
        vector<int>parent,size;
        public:
            DSU(int n){
                parent.resize(n);
                size.resize(n,1);
                for(int i=0;i<n;i++) parent[i]=i;
            }
        
        int findParent(int u){
            if(parent[u]==u)return u;
            return parent[u]= findParent(parent[u]);
        }
        void unionBySize(int u,int v){
            int pu = findParent(u);
            int pv = findParent(v);

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
        int findSize(int u){
            return size[u];
        }
    };
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {-1,1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int node = i*n+j;
                    for(int k=0;k<4;k++){
                        int x = i+dx[k];
                        int y = j+dy[k];
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1){
                            int adjNode = x*n+y;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int node = i*n+j;
                    unordered_set<int>st;
                    for(int k=0;k<4;k++){
                        int x = i+dx[k];
                        int y = j+dy[k];
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1){
                            int adjNode = x*n+y;
                            st.insert(ds.findParent(adjNode));
                        }
                    }
                    int size =0;
                    for(auto &it:st){
                        size+= ds.findSize(it);
                    }
                    maxi = max(maxi,size+1);
                }
            }
        }
        return maxi==INT_MIN?n*n:maxi;
    }
};