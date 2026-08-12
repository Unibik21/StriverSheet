class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = 0;
        int l = 0;
        int r = 0;
        unordered_map<int,int>freq;

        while(r<nums.size()){
            freq[nums[r]]++;
            while(freq[nums[r]]>k){
                freq[nums[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }
};