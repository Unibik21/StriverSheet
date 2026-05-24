class Solution {
public:
    int solve(int i,vector<int>&arr,int d,vector<int>&dp){
        if(dp[i]!=-1)return dp[i];
        int cnt1 = 0;
        int cnt2 = 0;
        int maxi= min(i+d,(int)arr.size()-1);
        for(int j=i+1;j<=maxi;j++){
            if(arr[j]<arr[i]){
                cnt1 = max(solve(j,arr,d,dp),cnt1);
            }
            else if(arr[j]>=arr[i])break;
        }
        int mini = max(0,i-d);
        for(int j=i-1;j>=mini;j--){
            if(arr[j]<arr[i]){
                cnt2 = max(solve(j,arr,d,dp),cnt2);
            }
            else if(arr[j]>=arr[i])break;
        }

        return dp[i]=1+max(cnt1,cnt2);
    }
    int maxJumps(vector<int>& arr, int d) {
        int maxi = 1;
        vector<int>dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,solve(i,arr,d,dp));
        }
        return maxi;
    }
};