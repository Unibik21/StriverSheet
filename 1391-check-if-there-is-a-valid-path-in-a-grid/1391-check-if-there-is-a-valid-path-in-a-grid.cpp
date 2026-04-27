class Solution {
public:
    bool check(int i,int j,int di,int dj,vector<vector<int>>& grid,unordered_map<int,vector<pair<int,int>>>&pts){
        int path = grid[di][dj];
        for(auto &k:pts[path]){
            int dx = di+k.first;
            int dy = dj+k.second;

            if(dx==i && dy==j)return true;
        }
        return false;
    }
    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,unordered_map<int,vector<pair<int,int>>>&pts){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return true;
        }
        int path = grid[i][j];
        for(auto k:pts[path]){
            int dx = k.first+i;
            int dy = k.second+j;
            if(dx>=0 && dx<grid.size() && dy>=0 && dy<grid[0].size() && vis[dx][dy]==0 && check(i,j,dx,dy,grid,pts)){
                vis[dx][dy]=1;
                if(dfs(dx,dy,grid,vis,pts))return true;
            }
        }

        return false;

    }
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int,vector<pair<int,int>>>pts;
        pts[1]={{0,-1},{0,1}};
        pts[2]={{-1,0},{1,0}};
        pts[3]={{1,0},{0,-1}};
        pts[4]={{0,1},{1,0}};
        pts[5]={{0,-1},{-1,0}};
        pts[6]={{0,1},{-1,0}};
       vector<vector<int>>vis(grid.size(),(vector<int>(grid[0].size(),0))); 
       vis[0][0]=1;
       return dfs(0,0,grid,vis,pts);
    }
};