class Solution {
public:
    bool check(vector<int>& nums) {
        int wr = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1] && wr==1)return false;
            else if(nums[i]>nums[i+1])wr++;
        }
        if(wr==1)return nums[nums.size()-1]<=nums[0];
        return true;
    }
};