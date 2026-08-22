class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int prod =1;
        int temp =n ;
        while(n!=0){
            int d = n%10;
            sum+=d;
            prod*=d;
            n=n/10;
        }

        return temp%(sum+prod)==0;
        
    }
};