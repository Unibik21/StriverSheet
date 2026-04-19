class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        sort(sources.begin(),sources.end(),[](auto &a,auto &b){
            return a[2]>b[2];
        });
        vector<vector<int>>grid(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(auto &i:sources){
            int c = i[2];
            int x = i[0];
            int y = i[1];
            grid[x][y]=c;
            q.push({c,{x,y}});
        }
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {-1,1,0,0};

        while(!q.empty()){
            auto i = q.front();
            q.pop();
            int x = i.second.first;
            int y = i.second.second;
            int c = i.first;     
                for(int l=0;l<4;l++){
                int cx = x + dx[l];
                int cy = y + dy[l];

                if(cx>=0 && cx<n && cy>=0 && cy<m && grid[cx][cy]==0){
                    grid[cx][cy]=c;
                    q.push({c,{cx,cy}});
                }
                
            }
        }

        return grid;

    }
};