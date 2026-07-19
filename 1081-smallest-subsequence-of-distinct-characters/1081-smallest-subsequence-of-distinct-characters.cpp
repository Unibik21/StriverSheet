class Solution {
public:
    string smallestSubsequence(string s1) {
        unordered_map<char,int>cnt;
        vector<int>vis(26,0);

        for(auto &i:s1)cnt[i]++;
        stack<char>st;
        for(auto &i:s1){
            if(!vis[i-'a']){
                while(!st.empty() && st.top()>i){
                    if(cnt[st.top()]>0){
                        vis[st.top()-'a']=0;
                        st.pop();
                    }
                    else{
                        break;
                    }
                }
                vis[i-'a']=1;
                st.push(i);
            }
            cnt[i]--;
        }
        string s = "";

        while(!st.empty()){s+=st.top(); st.pop();}
        reverse(s.begin(),s.end());
        return s;
    }
};