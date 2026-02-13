#include<iostream>
#include<vector>
using namespace std;

int solve(int i,vector<int>&ht,int mini,vector<int>&dp){
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    
    int st2 = INT_MAX;
    int st1 = solve(i-1,ht,mini,dp)+ abs(ht[i]-ht[i-1]);

    if(i>=2){
        int st2 = solve(i-2,ht,mini,dp)+ abs(ht[i]-ht[i-2]);
    }

    return dp[i] = min(st1,st2);

}

int main(){
    
}
