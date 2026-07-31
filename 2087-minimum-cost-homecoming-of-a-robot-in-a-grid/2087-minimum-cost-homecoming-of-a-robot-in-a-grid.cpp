class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& row, vector<int>& col) {
        int ans =0;

        while(start[0]>home[0]){ans+=row[--start[0]];}
        while(start[0]<home[0]){ans+=row[++start[0]];}
        while(start[1]<home[1]){ans+=col[++start[1]];}
        while(start[1]>home[1]){ans+=col[--start[1]];}

        return ans;
    }
};