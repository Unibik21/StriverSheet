class Solution {
public:
    int reverse(int x){
        int ans = 0;
        while(x!=0){
            int d = x%10;
            ans= ans*10+d;
            x=x/10;
        }
        return ans;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int mini = INT_MAX;
        unordered_map<int,int>ind;

        for(int i=0;i<nums.size();i++){
            if(ind.find(nums[i])!=ind.end()){
                mini = min(mini,i-ind[nums[i]]);
            }
            ind[reverse(nums[i])]=i;
        }

        return mini==INT_MAX?-1:mini;
    }
};