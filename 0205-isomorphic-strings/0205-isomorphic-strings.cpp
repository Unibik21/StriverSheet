class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s1;
        unordered_map<char,char>t1;
        bool b = true;
        for(int i=0;i<s.size();i++){
            if(s1.find(s[i])!=s1.end() || t1.find(t[i])!=t1.end()){
                b = (s1[s[i]]==t[i] && t1[t[i]]==s[i]);
                if(!b)return false;
            }
            else{
                s1[s[i]]=t[i];
                t1[t[i]]=s[i];
            }
        }
        return true;
    }
};