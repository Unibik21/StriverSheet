class Solution {
public:
    int prod(int n){
        int ans =1;
        while(n){
            ans*=n%10;
            n=n/10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(prod(n)%t==0){
                return n;
            }
            n++;
        }
    }
};