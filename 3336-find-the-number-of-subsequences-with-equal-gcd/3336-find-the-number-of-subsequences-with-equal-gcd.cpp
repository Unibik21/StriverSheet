class Solution {
public:
    int solve(int i,int gcd1,int gcd2,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i==nums.size()){
            if(gcd1==gcd2 && gcd1!=0)return 1;
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];
        long long mod = 1e9+7;
        long long skip = solve(i+1,gcd1,gcd2,nums,dp) % mod;
        long long take1 = solve(i+1,gcd(gcd1,nums[i]),gcd2,nums,dp) % mod;
        long long take2 = solve(i+1,gcd1,gcd(gcd2,nums[i]),nums,dp) % mod;

        return dp[i][gcd1][gcd2]=(skip+take1+take2)% mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int maxi = -1e9+7;
        for(auto &i:nums)maxi=max(maxi,i);
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));
        return (int)solve(0,0,0,nums,dp);
    }
};