class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = INT_MIN;
        int ind =-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                ind = i;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(ind!=i && nums[i]*2>maxi)return -1;
        }

        return ind;
    }
};