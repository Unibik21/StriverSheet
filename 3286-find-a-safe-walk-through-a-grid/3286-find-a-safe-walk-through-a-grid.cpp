class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<pair<pair<int,int>,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>best(n,vector<int>(m,-1));
        if(grid[0][0]==1){q.push({{0,0},health-1});best[0][0]=health-1;}
        else {q.push({{0,0},health}); best[0][0]=health;}
        vector<int>dx = {-1,1,0,0};
        vector<int>dy ={0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int h = q.front().second;
            q.pop();

            if(x==n-1 && y==m-1)return true;

            for(int i=0;i<4;i++){
                int cx = x+dx[i];
                int cy = y+dy[i];

                if(cx>=0 && cx<n && cy>=0 && cy<m){
                    int hel = h-grid[cx][cy];

                    if(hel>=1 && hel>best[cx][cy]){
                       best[cx][cy]=hel;
                       q.push({{cx,cy},hel}); 
                    }
                }
            }

        }

        return false;
    }
};