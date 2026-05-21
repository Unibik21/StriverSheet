class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int>dx = {0,0,1,-1,1,1,-1,-1};
        vector<int>dy = {-1,1,0,0,1,-1,1,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        if(grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]==1)return -1;
        if(grid[0][0]==0)dist[0][0]=1;
        pq.push({1,{0,0}});

        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();

            if(x==grid.size()-1 && y==grid[0].size()-1){
                return d;
            }

            for(int s=0;s<8;s++){
                int i = x+dx[s];
                int j = y+dy[s];

                if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==0 && dist[i][j]>dist[x][y]+1){
                    dist[i][j]=dist[x][y]+1;
                    pq.push({dist[i][j],{i,j}});
                }
            }
        }
        return -1;
    }
};