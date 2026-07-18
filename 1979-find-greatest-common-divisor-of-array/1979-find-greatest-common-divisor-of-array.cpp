class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];

        for(auto &i:nums){
            maxi = max(maxi,i);
            mini = min(mini,i);
        }
        return gcd(maxi,mini);
    }
};