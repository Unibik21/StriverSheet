class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        
        string ans = "";
        int i=0;
        while(i<s.size()){
            string temp;
            while(i<s.size() && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(temp.size()!=0)st.push(temp);
            i++;
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty())ans+=" ";
        }

        return ans;
        
    }
};