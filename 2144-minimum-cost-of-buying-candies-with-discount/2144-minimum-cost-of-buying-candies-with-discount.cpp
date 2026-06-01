class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());

        int c =0;
        for(int i=0;i<cost.size();i++){
            if((i+1)%3!=0)c+=cost[i];
        }

        return c;
    }
};