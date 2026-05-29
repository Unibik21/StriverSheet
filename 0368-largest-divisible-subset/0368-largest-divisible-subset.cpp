class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1),hash(nums.size());
        int maxi = 1;
        int idx = 0;
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                    if(dp[i]<1+dp[prev]){
                        dp[i]=1+dp[prev];
                        hash[i]=prev;
                    }
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                idx=i;
            }
        }
        vector<int>temp;
        while(hash[idx]!=idx){
            temp.push_back(nums[idx]);
            idx = hash[idx];
        }
        temp.push_back(nums[idx]);
        return temp;
    }
};