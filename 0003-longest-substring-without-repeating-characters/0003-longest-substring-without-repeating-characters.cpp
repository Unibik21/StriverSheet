class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int r =0;
        unordered_map<char,int>pos;
        int len = 0;
        while(r<s.size()){
            if(pos.find(s[r])!=pos.end()){
                l = max(l,pos[s[r]]+1);
            }
            pos[s[r]]=r;
            len = max(len,r-l+1);
            r++;
        }

        return len;
    }
};