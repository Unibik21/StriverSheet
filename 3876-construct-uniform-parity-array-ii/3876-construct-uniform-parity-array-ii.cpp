class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        bool a = false;
        for(auto &i:nums1){
            if(i<mini)mini=i;
            if(i%2!=0)a=true;
        }
        if(mini%2==0 && a)return false;
        return true;
    }
};