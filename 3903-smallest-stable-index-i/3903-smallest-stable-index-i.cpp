class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
      vector<int>maxi(nums.size());
      int ma = INT_MIN;
      int mi = INT_MAX;
      for(int i=0;i<nums.size();i++){
        ma = max(ma,nums[i]);
        maxi[i]=ma;
      }
      int ind = -1;
      for(int i=nums.size()-1;i>=0;i--){
        mi = min(mi,nums[i]);
        int ins = maxi[i]-mi;
        if(ins<=k)ind = i;
      }  
      return ind;
    }
};