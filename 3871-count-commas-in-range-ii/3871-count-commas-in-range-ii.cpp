class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long s = 1000;
        int c =1;
        
        while(s<=n){
            long long e = min(n, s*1000 -1);
            ans += (e-s+1)*c;

            s=s*1000;
            c++;
        }

        return ans;
    }
};