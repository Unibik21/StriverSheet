class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int>pse(nums.size());
        vector<int>nse(nums.size());
        vector<int>pge(nums.size());
        vector<int>nge(nums.size());

        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i])st.pop();
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            if(st.empty())pge[i]=-1;
            else pge[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            if(st.empty())nse[i]=nums.size();
            else nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i])st.pop();
            if(st.empty())nge[i]=nums.size();
            else nge[i]=st.top();
            st.push(i);
        }

        long long sum =0;
        for(int i=0;i<nums.size();i++){
            int ls = i-pse[i];
            int rs = nse[i]-i;
            int ll = i-pge[i];
            int rl = nge[i]-i;

            long long s = 1LL*nums[i]*ls*rs;
            long long l = 1LL*nums[i]*ll*rl;

            sum+=l-s;
        }
        return sum;
    }
};