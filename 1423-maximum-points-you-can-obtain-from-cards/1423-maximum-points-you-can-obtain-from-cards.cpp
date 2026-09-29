class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0;

        for(int i=0;i<k;i++)lsum+=cardPoints[i];
        int maxi = lsum;

        int l = k-1;
        int r = cardPoints.size()-1;

        while(l>=0){
            lsum-=cardPoints[l];
            rsum+=cardPoints[r];
            r--;
            l--;
            maxi = max(maxi,lsum+rsum);
        }
        return maxi;
    }
};