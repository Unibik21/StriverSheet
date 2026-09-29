class Solution {
public:
    bool solve(int i,int j,int cnt,vector<vector<char>>& grid,vector<vector<vector<int>>>&dp){
        if(i==grid.size() || j==grid[0].size())return false;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if(grid[i][j]==')')cnt--;
            else return false;
            return cnt==0;
        }
        if(grid[i][j]=='(')cnt++;
        if(grid[i][j]==')'){
            if(cnt==0)return false;
            else cnt--;
        }
        if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];
        return dp[i][j][cnt]=solve(i+1,j,cnt,grid,dp)||solve(i,j+1,cnt,grid,dp);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int cnt =0;
        if(grid[0][0]==')')return false;
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid.size()+grid[0].size(),-1)));
        return solve(0,0,0,grid,dp);
    }
};