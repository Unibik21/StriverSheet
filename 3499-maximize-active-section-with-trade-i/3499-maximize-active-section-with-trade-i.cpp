class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        int i=0;
        vector<int>blk;
        while(i<s.size()){
            int j=i;
            while(i<s.size() && s[i]==s[j]){
                i++;
            }
            if(s[j]=='0')blk.push_back(i-j);
        }

        int ans =0;
        for(auto &k:s){
            if(k=='1')ans++;
        }

        if(blk.size()<2)return ans;

        int maxi = 0;
        for(int j=0;j<blk.size()-1;j++){
            maxi=max(maxi,blk[j]+blk[j+1]);
        }

        return ans+maxi;
    }
};