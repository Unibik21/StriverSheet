class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int h = nums.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(target==nums[m])return m;
            if(nums[m]<=nums[h]){
                if(nums[m]<target && target<=nums[h])l=m+1;
                else h=m-1;
            }
            else{
                if(nums[m]>target && nums[l]<=target)h=m-1;
                else l=m+1;
            }
        }

        return -1;
    }
};