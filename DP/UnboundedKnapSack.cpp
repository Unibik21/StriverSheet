#include<iostream>
#include<vector>
using namespace std;


int knapsack(vector<int>w,vector<int>val,int wt,int i,vector<vector<int>>&dp){
    if(wt==0){
        return 0;
    }
    if(i==w.size()){
        return 0;
    }
    if(dp[i][wt]!=-1)return dp[i][wt];
    int take = 0;
    if(wt>=w[i]) take=val[i]+knapsack(w,val,wt-w[i],i,dp);
    int notTake = knapsack(w,val,wt,i+1,dp);

    return dp[i][wt]=max(take,notTake);
}

int main(){

}