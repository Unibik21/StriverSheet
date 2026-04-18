class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int mSum = sum;
        int n = cardPoints.size();
        int l = k-1;
        int r = n-1;
        while(l>=0){
            sum-=cardPoints[l];
            sum+=cardPoints[r];
            mSum = max(sum,mSum);
            l--;
            r--;
        }

        return mSum;
    }
};