class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size()-1;i++){
            st.insert(i+1);
        }
        int cnt =0;
        
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()){
                if(nums[i]==nums.size()-1){
                    cnt++;
                    if(cnt==2)st.erase(nums[i]);
                }
                else{
                    st.erase(nums[i]);
                }
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};