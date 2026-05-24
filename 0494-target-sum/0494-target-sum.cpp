class Solution {
public:
    int solve(int i,int t,vector<int>&nums,vector<vector<int>>&dp,int sum){
        if(i==nums.size()){
            if(t==0)return 1;
            return 0;
        }
        if(t<-sum || t>sum)return 0;
        if(dp[i][t+sum]!=-1)return dp[i][t+sum];
        int pos = solve(i+1,t-nums[i],nums,dp,sum);
        int neg = solve(i+1,t+nums[i],nums,dp,sum);

        return dp[i][t+sum]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        vector<vector<int>>dp(nums.size(),vector<int>(2*sum+1,-1));
        return solve(0,target,nums,dp,sum);
    }
};