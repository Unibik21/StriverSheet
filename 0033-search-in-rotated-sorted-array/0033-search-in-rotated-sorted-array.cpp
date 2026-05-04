class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;

            if(target==nums[m])return m;

            if(nums[m]<=nums[h]){
                if(target>nums[m] && nums[h]>=target){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            else{
                if(target<nums[m] && target>=nums[l]){
                    h=m-1;
                }
                else {
                    l=m+1;
                }
            }
        }
        return -1;
    }
};