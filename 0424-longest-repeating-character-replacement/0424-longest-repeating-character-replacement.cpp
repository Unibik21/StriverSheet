class Solution {
public:
    int characterReplacement(string s, int k) {
       unordered_map<char,int>freq;
       int maxf = 0;
       int l =0;
       int r =0;
       int maxLen =0;

       while(r<s.size()){
        freq[s[r]]++;
        maxf = max(maxf,freq[s[r]]);
        int diff = r-l+1-maxf;

        if(diff>k){
            freq[s[l]]--;
            l++;
            maxf=0;
            for(auto &i:freq){
                maxf=max(maxf,i.second);
            }
        }

        if(diff<=k)maxLen = max(maxLen,r-l+1);
        r++;
       } 

       return maxLen;
    }
};