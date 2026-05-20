class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){q.push({i,0}); grid[i][0]=0;}
            if(grid[i][m-1]==1){q.push({i,m-1}); grid[i][m-1]=0;}
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){q.push({0,j}); grid[0][j]=0;}
            if(grid[n-1][j]==1){q.push({n-1,j}); grid[n-1][j]=0;}
        }
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {1,-1,0,0};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int i= x+dx[k];
                int j= y+dy[k];

                if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};