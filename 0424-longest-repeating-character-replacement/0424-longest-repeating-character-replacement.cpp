class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r =0;
        int maxF = 0;
        int len =0;
        vector<int>freq(26,0);
        while(r<s.size()){
            freq[s[r]-'A']++;
            maxF = max(maxF,freq[s[r]-'A']);
            if(r-l+1-maxF>k){
                freq[s[l]-'A']--;
                l++;
            }
            if(r-l+1-maxF<=k){
                len= max(len,r-l+1);
            }
            r++;
        }
        return len;
    }
};