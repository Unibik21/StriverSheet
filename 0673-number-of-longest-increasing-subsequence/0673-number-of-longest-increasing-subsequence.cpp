class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>cnt(nums.size(),1);
        int maxi = 1;

        for(int i=0;i<nums.size();i++){
            for(int prev =0;prev<i;prev++){
                if(dp[i]<1+dp[prev] && nums[i]>nums[prev]){
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }
                else if(dp[i]==1+dp[prev] && nums[i]>nums[prev]){
                    cnt[i]+=cnt[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxi)sum+=cnt[i];
        }

        return sum;
    }
};