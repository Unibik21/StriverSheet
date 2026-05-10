class Solution {
public:
    int solve(int i,vector<int>& nums, int target,vector<int>&dp){
        if(i==nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi = INT_MIN;
        for(int j=i+1;j<nums.size();j++){
            if(abs(nums[j]-nums[i])<=target){
                int next = solve(j,nums,target,dp);
                if(next!=INT_MIN){
                    maxi=max(next+1,maxi);
                }
            }
        }

        return dp[i]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size()+1,-1);
        int ans = solve(0,nums,target,dp);
        return ans==INT_MIN?-1:ans;
    }
};