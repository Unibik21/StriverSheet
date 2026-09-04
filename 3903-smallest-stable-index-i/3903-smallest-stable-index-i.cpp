class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        vector<int>m(nums.size());
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            m[i]=maxi;
        }
        int mini = INT_MAX;
        int idx =-1;
        for(int i=nums.size()-1;i>=0;i--){
            mini = min(mini,nums[i]);
            if(m[i]-mini<=k){
                idx=i;
            }
        }

        return idx;
    }
};