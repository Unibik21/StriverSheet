class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init = image[sr][sc];
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {-1,1,0,0};
        queue<pair<int,int>>q;
        image[sr][sc]=color;
        q.push({sr,sc});
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        vis[sr][sc]=1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int i = x+dx[k];
                int j = y+dy[k];

                if(i>=0 && j>=0 && i<image.size() && j<image[0].size() && image[i][j]==init && !vis[i][j]){
                    image[i][j]=color;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        return image;
    }
};