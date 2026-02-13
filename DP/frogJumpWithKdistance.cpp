#include<iostream>
#include<vector>
using namespace std;

int solve(int i,vector<int>&ht,int mini,vector<int>&dp,int k){
    if(i==0)return 0;
    if(dp[i]!=-1) return dp[i]; 
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            int jump = solve(i-j,ht,mini,dp,k)+abs(ht[i]-ht[j]);
            mini= min(mini,jump);
        }
    }
    return dp[i]=mini;
}

int main(){
    
}