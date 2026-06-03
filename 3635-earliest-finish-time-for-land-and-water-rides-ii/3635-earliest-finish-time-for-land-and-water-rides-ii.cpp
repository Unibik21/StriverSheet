class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int lct = 1e9;
        int ans = 1e9;
        for(int i=0;i<landDuration.size();i++){
            lct=min(lct,landStartTime[i]+landDuration[i]);
        }

        int wct = 1e9;
        for(int i=0;i<waterDuration.size();i++){
            wct = min(wct,waterStartTime[i]+waterDuration[i]);
            int start= max(lct,waterStartTime[i]);
            ans = min(ans,start+waterDuration[i]);
        }

        for(int i=0;i<landDuration.size();i++){
            int start = max(wct,landStartTime[i]);
            ans = min(start+landDuration[i],ans);
        }

        return ans;



    }
};