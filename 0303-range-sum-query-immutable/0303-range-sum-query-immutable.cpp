class NumArray {
public:
    vector<int>pref;
    NumArray(vector<int>& nums) {
        pref.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(i==0)pref[i]=nums[i];
            else pref[i]=nums[i]+pref[i-1];
        }
    }
    
    int sumRange(int l, int r) {
        if(l==0)return pref[r];
        return pref[r]-pref[l-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */