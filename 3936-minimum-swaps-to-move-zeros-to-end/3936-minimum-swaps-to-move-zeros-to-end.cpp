class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i=0;
        int j =nums.size()-1;
        int cnt =0;
        while(i<j){
            while(i<j && nums[j]==0)j--;
            if(i==j)break;
            if(nums[i]==0){
                cnt++;
                j--;
            }
            i++;
        }
        return cnt;
    }
};