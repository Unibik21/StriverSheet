class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x =0;
        bool b = false;
        for(auto &i:nums){
            x^=i;
            if(i!=0){
                b=true;
            }
        }

        if(x!=0)return nums.size();
        
        if(b){
            return nums.size()-1;
        }

        return 0;

    }
};