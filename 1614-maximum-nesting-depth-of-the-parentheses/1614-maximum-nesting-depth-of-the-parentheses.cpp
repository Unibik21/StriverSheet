class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        stack<char>st;
        for(auto &i:s){
            if(i=='('){
                st.push(i);
                maxi=max(maxi,(int)st.size());
            }
            else if(i==')')st.pop();
        }
        return maxi;
    }
};