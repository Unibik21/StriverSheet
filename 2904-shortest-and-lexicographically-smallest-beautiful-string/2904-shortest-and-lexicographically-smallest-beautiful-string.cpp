class Solution {
public:
    bool solve(int len1,int s1,int len2,int s2,string &s){
        string a = s.substr(s1,len1);
        string b = s.substr(s2,len2);
        return a>b;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int ones = 0;
        for(auto &i:s){
            if(i=='1')ones++;
        }
        if(ones<k)return "";


        int l =0;
        int r =0;
        int len = s.size();
        int one =0;
        int idx = 0;

        while(r<s.size()){
            if(s[r]=='1')one++;
            while(one>k){
                if(s[l]=='1')one--;
                l++;
            }
            while(l<r && s[l]=='0')l++;
            if(one==k){
                if(len>r-l+1 || ( len==r-l+1 && solve(len,idx,r-l+1,l,s))){
                    len=r-l+1;
                    idx=l;
                }
            }
            r++;
        }

        return s.substr(idx,len);
    }
};