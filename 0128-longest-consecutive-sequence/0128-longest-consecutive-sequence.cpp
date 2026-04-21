class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;

        if(nums.size()==0)return 0;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxi = INT_MIN;
        for(auto &i:st){
            if(st.find(i+1)!=st.end())continue;
            int curr =1;
            int n = i;
            while(st.find(n-1)!=st.end()){curr++; n--;}
            maxi = max(curr,maxi);
        }

        return maxi;
    }
};