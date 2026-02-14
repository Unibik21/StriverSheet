#include<iostream>
#include<vector>
using namespace std;

int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    for(int k=i;k<j;k++){
        int steps = (arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
        mini = min(mini,steps);
    }
    return dp[i][j]=mini;
}

int main(){

}