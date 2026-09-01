class Solution {
public:
    int minMoves(vector<string>& cr, int energy) {
        int n = cr.size();
        int m = cr[0].size();

        vector<vector<int>>marker(n,vector<int>(m,-1));
        int total =0;
        int sr=0;
        int sc =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cr[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                else if(cr[i][j]=='L'){
                    marker[i][j]=total++;
                }
            }
        }

        vector<vector<vector<vector<bool>>>>vis(n,vector<vector<vector<bool>>>(m,vector<vector<bool>>(energy+1,vector<bool>(1<<total,false))));
        queue<array<int,4>>q;
        int target = (1<<total)-1;
        q.push({sr,sc,energy,0});
        vis[sr][sc][energy][0]=true;
        int steps =0;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [r,c,e,mask] = q.front();
                q.pop();

                if(mask==target)return steps;

                for(int d =0;d<4;d++){
                    int x = r+dx[d];
                    int y = c+dy[d];
                    int ne = e-1;

                    if(x>=n || x<0 || y>=m || y<0 || ne<0 || cr[x][y]=='X')continue;
                    if(cr[x][y]=='R')ne=energy;
                    int nmask =mask;
                    if(cr[x][y]=='L'){
                        nmask|= (1<<marker[x][y]);
                    }
                    if(!vis[x][y][ne][nmask]){
                        q.push({x,y,ne,nmask});
                        vis[x][y][ne][nmask]=true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};