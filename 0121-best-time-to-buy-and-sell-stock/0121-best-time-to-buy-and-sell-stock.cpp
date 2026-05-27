class Solution {
public:
    int maxProfit(vector<int>& p) {
       int mini = p[0];
       int prof = -1;

       for(int i=1;i<p.size();i++){
            if(mini<p[i])prof = max(prof,p[i]-mini);
            else{
                mini = p[i];
            }
       }
       return prof==-1?0:prof;
    }
};