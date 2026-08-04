class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int>ans;
        int prev = nums[0];
        int i=1;
        while(i<nums.size()){
            if(prev+1==nums[i]){
                prev = nums[i];
                i++;
            }
            else{
                ans.push_back(prev+1);
                prev= prev+1;
            }
        }

        return ans;
    }
};