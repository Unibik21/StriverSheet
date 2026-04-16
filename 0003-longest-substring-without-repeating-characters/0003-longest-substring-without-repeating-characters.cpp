class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>ind;
        int l =0;
        int r =0;
        int len = 0;
        while(r<s.size()){
            
            if(ind.find(s[r])!=ind.end()){
                if(l<=ind[s[r]]){
                    l=ind[s[r]]+1;
                }
            }

            len = max(len,r-l+1);

            ind[s[r]]=r;
            r++;

        }

        return len;
    }
};