class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int maxLen = 0;
        int hash[256];
        for(int i=0;i<256;i++)hash[i]=-1;
        while(r<s.size()){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l) l= hash[s[r]]+1;
            maxLen = max(maxLen,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};