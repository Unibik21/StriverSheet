class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*sum+1,0));
        if(target < -sum || target > sum)return 0;
        int n = nums.size();
        int m = 2*sum+1;
        dp[n][sum]=1;

        for(int i=n-1;i>=0;i--){
            for(int t=-sum;t<=sum;t++){
                int ways= 0;
                if(t-nums[i]>=-sum)ways+=dp[i+1][t-nums[i]+sum];
                if(t+nums[i]<=sum)ways+=dp[i+1][t+nums[i]+sum];
                dp[i][t+sum]=ways;
            }
        }

        return dp[0][target+sum];
    }
};