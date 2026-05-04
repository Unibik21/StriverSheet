class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l =0;
        int h = nums.size()-1;
        if(target>nums[h])return h+1;
        int ans =-1;
        while(l<=h){
            int m = l+(h-l)/2;

            if(nums[m]==target)return m;
            else if(nums[m]>target){
                ans = m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }

        return ans;
    }
};