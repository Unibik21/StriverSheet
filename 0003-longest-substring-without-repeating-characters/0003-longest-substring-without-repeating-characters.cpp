class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>ind(256,-1);
        int r=0;
        int l=0;
        int len = 0;
        while(r<s.size()){
           if(ind[s[r]]!=-1){
            if(l<=ind[s[r]])l= ind[s[r]]+1;
           }
           len = max(len,r-l+1);
           ind[s[r]]=r;
           r++;
        }
        return len;
    }
};