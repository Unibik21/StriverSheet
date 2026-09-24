class Solution {
public:
    bool solve(int num,int i){
        int sum =0;
        while(num!=0){
            sum+=num%10;
            num=num/10;
        }
        return sum==i;
    }
    int smallestIndex(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
            if(solve(nums[i],i))return i;
       } 
       return -1;
    }
};