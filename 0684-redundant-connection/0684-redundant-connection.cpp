class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int px = find(x);
        int py = find(y);

        if(px==py)return;

        if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else {
            parent[py]=px;
            rank[px]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

        vector<int>ans(1);

        for(auto &i:edges){
            int x = i[0];
            int y = i[1];
            int px = find(x);
            int py = find(y);
            if(px==py){
                ans={x,y};
            }
            Union(x,y);
        }

        return ans;
    }
};