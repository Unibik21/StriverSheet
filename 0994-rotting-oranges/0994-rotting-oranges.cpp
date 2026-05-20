class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<int>dx = {0,0,-1,1};
       vector<int>dy = {1,-1,0,0};
       int mini =0;
       queue<int>q;
       int fresh =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    int node = (i*m)+j;
                    q.push(node);
                }
                if(grid[i][j]==1)fresh++;
            }
        }

        while(!q.empty() && fresh>0){
            int size = q.size();
            for(int l=0;l<size;l++){
                int node = q.front();
                q.pop();

                int i = node/m;
                int j = (node%m);

                for(int k=0;k<4;k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    int n1 = (x*m)+y;
                    if(x<n && x>=0 && y<m && y>=0 && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push(n1);
                        fresh--;
                    }
                }

            }
            mini++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return mini;
    }
};