class Solution {
public:
    long long solve(int i,int j,vector<int>& r,vector<int>& f, vector<vector<long long>>&dp){
        if(i==r.size())return 0;
        if(j==f.size())return 1e18;
        if(dp[i][j]!=-1)return dp[i][j];
        long long take = abs(r[i]-f[j])+ solve(i+1,j+1,r,f,dp);
        long long skip = solve(i,j+1,r,f,dp);

        return dp[i][j]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        sort(r.begin(),r.end());
        
        vector<int>fact;
        for(int i=0;i<f.size();i++){
            while(f[i][1]!=0){
                fact.push_back(f[i][0]);
                f[i][1]--;
            }
        }

        sort(fact.begin(),fact.end());
        vector<vector<long long>>dp(r.size(),vector<long long>(fact.size(),-1));
        return solve(0,0,r,fact,dp);
    }
};