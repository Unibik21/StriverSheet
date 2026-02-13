#include<iostream>
#include<vector>
using namespace std;

    int solve(int i,int k,vector<int>&arr,vector<vector<int>>&dp){
        
        if(i==0){
            if(k==0 && arr[i]==0) return 2;
            if(k==0 || arr[i]==k) return 1;
            return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int take = 0;
        if(k>=arr[i])take=solve(i-1,k-arr[i],arr,dp);
        int notTake = solve(i-1,k,arr,dp);

        return dp[i][k]=take+notTake;
    }



int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cin>>d;


    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    if((sum+d)%2!=0)return 0;

    vector<vector<int>>dp(n,vector<int>(((sum+d)/2)+1,-1));
    return solve(n-1,(sum+d)/2,arr,dp);
}
