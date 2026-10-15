class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum =0;

        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                set<int>st;
                for(int k=i;k<=j;k++)st.insert(nums[k]);
                int n = st.size();
                sum+=n*n;
            }
        }

        return sum;
    }
};