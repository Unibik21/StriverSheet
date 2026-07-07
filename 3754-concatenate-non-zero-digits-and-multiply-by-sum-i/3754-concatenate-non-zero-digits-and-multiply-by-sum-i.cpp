class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum =0;
        int x = 0;
        int i =0;
        while(n!=0){
            if(n%10!=0){
                x = ((n%10)*(pow(10,i)))+x;
                i++;
            }
            sum+=n%10;
            n=n/10;
        }

        return (long long)x*sum;
    }
};