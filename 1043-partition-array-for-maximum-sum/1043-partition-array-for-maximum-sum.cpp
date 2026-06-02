class Solution {
public:
    int solve(int i,int k,vector<int>&arr,vector<int>&dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi =-1;
        int len = min((int)arr.size()-1,i+k-1);
        for(int j=i;j<=len;j++){
           int m = -1;
           for(int k=i;k<=j;k++){
                m = max(m,arr[k]);
            }
            maxi = max(maxi, m*(j-i+1)+solve(j+1,k,arr,dp));
        }

        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return solve(0,k,arr,dp);  
    }
};