class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int ans = -1;
        int l = 0;
        int h = nums.size()-1;
        if(t>nums[nums.size()-1])return nums.size();
        else if(t<nums[0])return 0;

        while(l<=h){
            int m = l+(h-l)/2;

            if(nums[m]==t)return m;
            else if(nums[m]>t){ans =m;h=m-1;}
            else l=m+1;
        }

        return ans;
    }
};