class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = 1e9;

        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                int wstart = landStartTime[i]+landDuration[i];
                wstart = max(wstart,waterStartTime[j]);
                ans = min(ans,wstart+waterDuration[j]);

                int lstart = waterStartTime[j]+waterDuration[j];
                lstart = max(lstart,landStartTime[i]);
                ans = min(ans,lstart+landDuration[i]);
            }
        }

        return ans;
    }
};