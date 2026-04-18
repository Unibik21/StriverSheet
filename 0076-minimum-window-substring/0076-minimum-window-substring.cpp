class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(256,0);
        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }

        int r =0;
        int l=0;
        int cnt =0;
        int len = INT_MAX;
        int sind =-1;

        while(r<s.size()){
            if(freq[s[r]]>0)cnt++;
            freq[s[r]]--;

            while(cnt==t.size()){
                if(len>r-l+1){
                    len=r-l+1;
                    sind = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0)cnt--;
                l++;
            }

            r++;
        }

        return sind==-1?"":s.substr(sind,len);
    }
};