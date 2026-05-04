class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto s = lower_bound(nums.begin(),nums.end(),target);
        auto e = upper_bound(nums.begin(),nums.end(),target);

        if(e-s==0)return {-1,-1};
        return {int(s-nums.begin()),int(e-nums.begin()-1)}; 
    }
};