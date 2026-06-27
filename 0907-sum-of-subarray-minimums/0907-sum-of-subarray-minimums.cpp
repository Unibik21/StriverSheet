class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse(arr.size());
        vector<int>nse(arr.size());
        int mod = 1e9+7;
        stack<int>st;
        pse[0]=-1;
        st.push(0);
        for(int i=1;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();
        nse[arr.size()-1]=arr.size();
        st.push(arr.size()-1);
        for(int i=arr.size()-2;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(st.empty())nse[i]=arr.size();
            else nse[i]=st.top();
            st.push(i);
        }

        long long sum =0;
        for(int i=0;i<arr.size();i++){
            int le = i-pse[i];
            int re = nse[i]-i;
            sum = (sum+(le*re*1LL*arr[i])) % mod;
        }

        return sum%mod;
    }
};