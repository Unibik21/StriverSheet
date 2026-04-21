class Solution {
public:
    vector<int>rank;
    vector<int>parent;

    int find(int x){
        if(parent[x]==x){
            return x; 
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int px = find(x);
        int py = find(y);

        if(px==py)return;

        if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }

    }


    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &i:allowedSwaps){
            int x = i[0];
            int y = i[1];
            Union(x,y);
        }

        unordered_map<int, unordered_map<int,int>>grp;
        for(int i=0;i<n;i++){
            int p = find(i);
            grp[p][source[i]]++;
        }

        int diff =0;

        for(int i=0;i<n;i++){
            int p = find(i);
            if(grp[p][target[i]]>0){
               grp[p][target[i]]--; 
            }
            else{
                diff++;
            }
        }
        return diff;

    }
};