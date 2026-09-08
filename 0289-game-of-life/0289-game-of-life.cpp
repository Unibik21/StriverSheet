class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> mat = board;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int live =0;
                vector<int>dx = {1,1,1,-1,-1,-1,0,0};
                vector<int>dy = {-1,0,1,-1,0,1,1,-1};

                for(int k=0;k<8;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(nx>=0 && nx<mat.size() && ny<mat[0].size() && ny>=0){
                        if(mat[nx][ny]==1)live++;
                    }
                }

                if(live<2 && mat[i][j]==1)board[i][j]=0;
                if(live>3 && mat[i][j]==1)board[i][j]=0;
                if(live==3 && mat[i][j]==0)board[i][j]=1;
            }
        }

    }
};