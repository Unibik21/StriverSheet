class Solution {
public:
    bool solve(int c,int x){
        return (long long)c*c<=x;
    }
    int mySqrt(int x) {
        int l = 0;
        int h = x;
        int ans =-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(solve(m,x)){
                ans = m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
};