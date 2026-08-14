class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>freq;
        int l =0;
        int maxi = 0;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            while(freq[s[r]]>2){
                freq[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
        }

        return maxi;
    }
};