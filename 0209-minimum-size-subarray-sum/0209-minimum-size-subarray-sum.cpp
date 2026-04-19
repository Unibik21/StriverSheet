class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int l=0;
        int r=0;
        int sum=0;

        while(r<nums.size()){
            sum+=nums[r];
            while(sum>=target){
                len = min(len,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }

        return len==INT_MAX?0:len;
    }
};