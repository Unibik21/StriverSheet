class Solution {
public:
    bool match(int i,string &seq, string &word){
        for(int j=0;j<word.size();j++){
            if(seq[i+j]!=word[j])return false;
        }
        return true;
    }
    int solve(int i,string &seq, string &word,vector<int>&dp){
        if(i>=seq.size())return 0;
        if(dp[i]!=-1)return dp[i];
        if(match(i,seq,word)){
            return dp[i]=1+solve(i+word.size(),seq,word,dp);
        }
        return dp[i]=0;
    }
    int maxRepeating(string sequence, string word) {
        int maxi = 0;
        vector<int>dp(sequence.size()+1,-1);
        for(int i=0;i<sequence.size();i++){
            maxi=max(maxi,solve(i,sequence,word,dp));
        }

        return maxi;
    }
};