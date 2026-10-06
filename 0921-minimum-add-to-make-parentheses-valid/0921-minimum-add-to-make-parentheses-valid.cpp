class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<int>st;
       int ans =0;
       for(auto &i:s){
            if(i=='(')st.push(1);
            else{
                if(!st.empty())st.pop();
                else ans++;
            }
       }
       if(!st.empty())ans+=(int)st.size();

       return ans;
    }
};