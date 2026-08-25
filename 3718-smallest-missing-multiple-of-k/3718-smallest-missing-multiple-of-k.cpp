class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for(auto &i:nums){
            if(i>maxi)maxi=i;
        }

        for(int i=k;i<=maxi+k;i+=k){
            bool present = false;
            for(int j=0;j<nums.size();j++){
                if(i==nums[j]){
                    present = true;
                    break;
                }
            }
            if(!present){
                return i;
            }
        }
        return -1;
    }
};