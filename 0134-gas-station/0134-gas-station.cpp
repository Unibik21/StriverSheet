class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            int tank =0;
            bool b = true;
            for(int j=0;j<gas.size();j++){
                tank+=gas[(i+j)%gas.size()];
                tank-=cost[(i+j)%gas.size()];
                if(tank<0){
                    b=false;
                    if(i<j)i=j;
                    break;
                }
            }
            if(b)return i;
        }

        return -1;


    }
};