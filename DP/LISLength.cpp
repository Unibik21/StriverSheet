#include<iostream>
#include<vector>
using namespace std;

int solve(int i,int prev,vector<int>&arr,vector<vector<int>>&dp){
    if(i==arr.size())return 0;
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    int len = solve(i+1,prev,arr,dp);
    if(prev==-1 || arr[prev]<arr[i]){
        len = max(len,1+solve(i+1,i,arr,dp));
    }

    return dp[i][prev+1]=len;
}

int main(){

}