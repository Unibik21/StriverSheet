class Solution {
public: 
    int lb(vector<int>& nums, int t){  
        int l = 0;
        int h = nums.size()-1;
        if(t<nums[l] || t>nums[h])return -1;
        int ans =-1;
        while(l<=h){
            int m = l+(h-l)/2;

            if(nums[m]<=t){
                l=m+1;
                if(nums[m]==t){
                    ans = m;
                }
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
    int ub(vector<int>& nums, int t){
        int l = 0;
        int h = nums.size()-1;
        if(t<nums[l] || t>nums[h])return -1;
        int ans =-1;
        while(l<=h){
            int m = l+(h-l)/2;

            if(nums[m]>=t){
                h=m-1;
                if(nums[m]==t){
                    ans = m;
                }
            }
            else{
                l=m+1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return {-1,-1};
        int s = ub(nums,target);
        if(s==-1)return {-1,-1};
        int e = lb(nums,target);
        return {s,e};
    }
};