class Solution {
public:
    string minWindow(string s, string t) {
        int l= 0;
        int r=0;
        int hash[256];
        for(int i=0;i<256;i++)hash[i]=0;
        for(int i=0;i<t.size();i++)hash[t[i]]++;
        int sind=-1;
        int minLen = 1e9;
        int m =t.size();
        int cnt =0;
        while(r<s.size()){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(minLen>r-l+1){
                    minLen=r-l+1;
                    sind=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }

        return sind==-1?"":s.substr(sind,minLen);
    }
};