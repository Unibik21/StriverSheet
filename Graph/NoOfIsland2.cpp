#include<iostream>
#include<vector>
using namespace std;

class Disjointset{
    vector<int>parent,size;

    public:
        Disjointset(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)parent[i]=i;
        }
    
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
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

bool isValid(int i ,int j,int n, int m){
    return (i>=0 && i<n && j>=0 && j<m);
}

vector<int>numsOfIslands(int n,int m,vector<vector<int>>&operations){
    Disjointset ds(n*m);
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<int>ans;
    int cnt=0;
    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,-1,1};
    for(int i=0;i<operations.size();i++){
        int row = operations[i][0];
        int col = operations[i][1];

        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        
        vis[row][col]=1;
        cnt++;

        for(int k=0;k<4;k++){
            int r = row+dr[k];
            int c = col+dc[k];
            if(isValid(r,c,n,m)){
                if(vis[r][c]==1){
                    int curr_node = row*m+col;
                    int adj_node = r*m+c;
                    if(ds.findParent(curr_node)!=ds.findParent(adj_node)){
                        cnt--;
                        ds.unionBySize(curr_node,adj_node);
                    }
                }
            }
        }

        ans.push_back(cnt);

    }

    return ans;
}

int main(){

}