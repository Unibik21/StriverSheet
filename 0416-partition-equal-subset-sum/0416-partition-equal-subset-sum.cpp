class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%2!=0)return false;

        sum = sum/2;
        vector<vector<bool>>dp(nums.size(),vector<bool>(sum+1,false));
        int n = nums.size();
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=sum){
            dp[0][nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int k=1;k<=sum;k++){
                bool nottake= dp[i-1][k];
                bool take = false;
                if(nums[i]<=k){
                    take = dp[i-1][k-nums[i]];
                }

                dp[i][k]=nottake||take;
            }
        }

        return dp[n-1][sum];
    }
};