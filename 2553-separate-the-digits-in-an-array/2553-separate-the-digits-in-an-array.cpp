class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
            int num = nums[i];
            while(num!=0){
                int d = num%10;
                ans.insert(ans.begin(),d);
                num=num/10;
            }
        }
        return ans;
    }
};