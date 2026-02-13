#include<iostream>
#include<vector>
using namespace std;


int solve(vector<vector<int>>&days,int i,int last,vector<vector<int>>&dp){
    if(i==days.size()){
        return 0;
    }
    if(dp[i][last]!=-1) return dp[i][last];
    int maxi = 0;
    for(int j=0;j<3;j++){
        if(j!=last){
            maxi = max(maxi,days[i][j]+solve(days,i+1,j,dp));
        }
    }
    return dp[i][last]=maxi;
}

int main(){

}