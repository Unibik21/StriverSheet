class Solution {
public:
    static int longestValidParentheses(string& s) {
        int n=s.size();
        int N=3e4;
        vector<int>st(N); 
        int top=-1;
        if (n<2) return 0;
        top=-1;
        vector<int>dp(N,0);
        int ans=0;
        for(int i=0; i<n; i++){
            if (s[i]=='(') {
                st[++top]=i;
            }
            else{ 
                if (top>=0){
                    int x=st[top--];
                    dp[i]=i-x+1;
                    if (x>=1) dp[i]+=dp[x-1];
                }
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};