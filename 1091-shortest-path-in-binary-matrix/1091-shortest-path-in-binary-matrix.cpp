class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int>dx ={0,0,-1,1,1,1,-1,-1};
        vector<int>dy ={-1,1,0,0,1,-1,-1,1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        dist[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n-1 && y==m-1)return dist[x][y];
            for(int s=0;s<8;s++){
                int i = x+dx[s];
                int j = y+dy[s];

                if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==0 && dist[i][j]>dist[x][y]+1){
                    dist[i][j]=dist[x][y]+1;
                    q.push({i,j});
                }
            }
        }
        return -1;
    }
};