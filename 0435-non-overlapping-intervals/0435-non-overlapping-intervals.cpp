class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1)return 0;
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });

        int prev = INT_MIN;
        int num =0;
        for(auto &i: intervals){
            if(prev<=i[0]){num++; prev=i[1];}
        }
        return intervals.size()-num;
    }
};