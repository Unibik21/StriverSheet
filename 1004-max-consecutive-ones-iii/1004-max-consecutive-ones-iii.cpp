class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0 =0;
        int l=0;
        int r=0;
        int len =0;
        while(r<nums.size()){
            if(nums[r]==0)cnt0++;
            if(cnt0>k){
                if(nums[l]==0)cnt0--;
                l++;
            }
            len= max(len,r-l+1);
            r++;
        }
        return len;
    }
};