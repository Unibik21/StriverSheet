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
    }; 
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        int mini = max(grid[n-1][n-1],grid[0][0]);
        int maxi = grid[n-1][n-1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi = max(grid[i][j],maxi);
            }
        }
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {-1,1,0,0};
        for(int t = mini;t<=maxi;t++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(t>=grid[i][j]){
                        int node = i*n+j;
                        for(int k=0;k<4;k++){
                            int x= i+dx[k];
                            int y =j+dy[k];

                            if(x>=0 && y>=0 && x<n && y<n && grid[x][y]<=t){
                                int adjNode = x*n+y;
                                ds.unionBySize(node,adjNode);
                            }
                        }
                    }
                }
            }
            if(ds.findParent(0)==ds.findParent(n*n-1))return t;
        }
        return -1;
    }
};