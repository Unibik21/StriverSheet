class Solution {
public:
    bool solve(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i==nums.size()-1){
            return nums[i]==sum;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int nottake = solve(i+1,sum,nums,dp);
        int take = false;

        if(nums[i]<=sum)take = solve(i+1,sum-nums[i],nums,dp);

        return dp[i][sum]=nottake||take;
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%2!=0)return false;

        sum = sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return solve(0,sum,nums,dp);
    }
};