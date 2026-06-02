class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,0);

        for(int i=arr.size()-1;i>=0;i--){
            int maxi =-1;
            int len = min((int)arr.size()-1,i+k-1);
            for(int j=i;j<=len;j++){
                int m = -1;
                for(int k=i;k<=j;k++){
                    m = max(m,arr[k]);
                }
                maxi = max(maxi, m*(j-i+1)+dp[j+1]);
            }   
            dp[i]=maxi;
        } 

        return dp[0]; 
    }
};