class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int curr =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            curr+=i*nums[i];
        }
        int maxi = curr;
        int r = nums.size()-1;

        while(r>0){
            curr+=sum;
            curr-=(nums.size())*nums[r];
            maxi = max(maxi,curr);
            r--;
        }

        return maxi;
    }
};