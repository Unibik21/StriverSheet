#include<iostream>
#include<vector>
using namespace std;


int rodCutting(vector<int>&price,int i,int N,vector<int>dp){
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int maxi =0;
    for(int j=0;j<N;j++){
        int cut = 0;
        if(j+1<=i)cut+=price[j]+rodCutting(price,i-(j+1),N,dp);
        maxi = max(cut, maxi);
    }

    return dp[i]=maxi;
}

int main(){

}