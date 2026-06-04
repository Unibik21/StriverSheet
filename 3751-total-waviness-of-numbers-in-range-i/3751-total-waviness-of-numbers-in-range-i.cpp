class Solution {
public:
    int solve(int i){
        int d1 = -1;
        int d2 = -1;
        int d3 = -1;
        d1 = i%10;
        i=i/10;
        if(i==0)return 0;
        d2 = i%10;
        i=i/10;
        if(i==0)return 0;
        d3 = i%10;
        i=i/10;
        int cnt =0;
        if(d2>d1 && d2>d3)cnt++;
        if(d2<d1 && d2<d3)cnt++;
        while(i>0){
            d1 = d2;
            d2 = d3;
            d3 = i%10;
            i=i/10;
            if(d2>d1 && d2>d3)cnt++;
            if(d2<d1 && d2<d3)cnt++;
        }

        return cnt;

    }
    int totalWaviness(int num1, int num2) {
        int cnt =0;
        for(int i=num1;i<=num2;i++){
           cnt+=solve(i); 
        }

        return cnt;
    }
};