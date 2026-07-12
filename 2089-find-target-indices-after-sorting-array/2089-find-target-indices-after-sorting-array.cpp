class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int j = upper_bound(nums.begin(),nums.end(),target)-nums.begin();

        vector<int>ans;
        for(int k=i;k<j;k++){
            ans.push_back(k);
        }

        return ans;
    }
};