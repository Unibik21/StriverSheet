class Solution {
public:
    int solve(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        int takei = nums[i]+ min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej = nums[j] + min(solve(i,j-2,nums),solve(i+1,j-1,nums));

        return max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        int s1 = solve(0,nums.size()-1,nums);
        int sum =0;
        for(auto &i:nums)sum+=i;
        int s2= sum-s1;
        return s1>=s2;
    }
};