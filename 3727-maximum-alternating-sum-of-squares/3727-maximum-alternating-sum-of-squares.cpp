class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        for(auto &i:nums)i=abs(i);
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            sum+=nums[r]*nums[r];
            sum-=nums[l]*nums[l];
            r--;
            l++;
        }
        if(r==l){
            sum+=nums[r]*nums[r];
        }

        return sum;
    }  
};