class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){k--; st.pop();}
            st.push(num[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        string res = "";
        if(st.empty())return "0";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(!res.empty() && res.back()=='0')res.pop_back();
        if(res.empty())return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};