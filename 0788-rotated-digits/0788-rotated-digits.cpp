class Solution {
public:
    bool solve(int x){
        bool done = false;
        while(x!=0){
            int d = x%10;
            if(d==2 || d==5 || d==6 || d==9)done=true;
            else if(d==3 || d==4 || d==7)return false;
            x=x/10;
        }
        return done;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(solve(i))cnt++;
        }
        return cnt;
    }
};