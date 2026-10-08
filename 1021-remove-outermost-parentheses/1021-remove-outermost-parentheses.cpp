class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(1);
            }
            else{
                if(s[i]==')')st.pop();
                else st.push(1);
                
                if(!st.empty())ans+=s[i];
            }
        }
        return ans;
    }
};