class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int idx1 = -1;
        int idx2 = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                mini = nums[i];
                idx2 = i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                idx1=i;
            }
        }

        if(idx1==idx2)return 1;
        int n = nums.size();
        return min({max(idx1,idx2)+1,max(n-idx1,n-idx2),idx1+n-idx2+1, idx2+n-idx1+1});
    }
};