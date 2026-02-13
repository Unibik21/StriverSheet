#include<iostream>
#include<vector>
using namespace std;


int solve(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(j1>=grid[0].size() || j1<0 || j2>=grid[0].size() || j2<0) return -1e9;
    if(i==grid.size()-1){
        return j1==j2?grid[i][j2]:grid[i][j2]+grid[i][j1];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi =0;
    int curr = j1==j2?grid[i][j2]:grid[i][j2]+grid[i][j1];
    for(int d1=-1;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            int ans = curr+solve(i+1,j1+d1,j2+d2,grid,dp);
            maxi = max(maxi,ans);
        }
    }

    return dp[i][j1][j2]=maxi;
}


int main(){

}