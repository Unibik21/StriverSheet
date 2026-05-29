class Solution {
public:
    bool check(string &a,string &b){
        if(a.size()!=b.size()+1)return false;
        int wrng =0;
        int i =0;
        int j =0;
        while(j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                if(wrng==1)return false;
                wrng++;
                i++;
            }
        }
        return wrng<=1;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), [](string &a,string &b){
            return a.size()<b.size();
        });
       vector<int>dp(words.size(),1);
       int maxi =1;
       for(int i=0;i<words.size();i++){
        for(int prev =0;prev<i;prev++){
            if(check(words[i],words[prev])){
                dp[i]=max(dp[i],1+dp[prev]);
            }
        }
        maxi = max(maxi,dp[i]);
       }
       return maxi; 
    }
};