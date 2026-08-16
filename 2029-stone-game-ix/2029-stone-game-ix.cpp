class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int one =0;
        int two =0;
        int zero =0;

        for(auto &i:stones){
            if(i%3==0)zero++;
            else if(i%3==1)one++;
            else two++;
        }

        if(zero%2==0){
            return one>=1 && two>=1;
        }

        return abs(one-two)>2;
    }
};