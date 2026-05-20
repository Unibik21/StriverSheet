class Solution {
public:
    void solve(vector<vector<char>>& b) {
        vector<vector<bool>>grid(b.size(),vector<bool>(b[0].size(),false));
        queue<pair<int,int>>q;

        for(int i=0;i<b.size();i++){
            if(b[i][0]=='O')q.push({i,0});
            if(b[i][b[0].size()-1]=='O')q.push({i,b[0].size()-1});
        }
        for(int j=0;j<b[0].size();j++){
            if(b[0][j]=='O')q.push({0,j});
            if(b[b.size()-1][j]=='O')q.push({b.size()-1,j});
        }
        vector<int>dx = {0,0,-1,1};
        vector<int>dy={-1,1,0,0};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            grid[x][y]=true;

            for(int k=0;k<4;k++){
                int i = x+dx[k];
                int j = y+dy[k];

                if(i>=0 && j>=0 && i<b.size() && j<b[0].size() && b[i][j]=='O' && !grid[i][j]){
                    q.push({i,j});
                }
            }
        }

        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(grid[i][j]==true){
                    b[i][j]='O';
                }
                else{
                    b[i][j]='X';
                }
            }
        }
    }
};