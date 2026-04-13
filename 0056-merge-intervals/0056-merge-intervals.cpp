class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        int i =0;
        while(i<n){
            int currS = intervals[i][0];
            int currE = intervals[i][1];

            while(i<n-1 && currE>=intervals[i+1][0]){
                currE = max(currE,intervals[i+1][1]);
                i++;
            }

            ans.push_back({currS,currE});
            i++;

        }
        return ans;
    }
};