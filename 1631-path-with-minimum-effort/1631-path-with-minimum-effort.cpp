class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        vector<int>dx = {-1,1,0,0};
        vector<int>dy = {0,0,-1,1};
        int n = h.size();
        int m = h[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));

        effort[0][0]=0;
        while(!pq.empty()){
            auto it =pq.top();
            int eff = it.first;
            int x= it.second.first;
            int y = it.second.second;
            pq.pop();

            if(x==n-1 && y==m-1)return eff;

            for(int s=0;s<4;s++){
                int i = x+dx[s];
                int j = y+dy[s];

                if(i>=0 && i<n && j>=0 && j<m && effort[i][j]>max(eff,abs(h[x][y]-h[i][j]))){
                    effort[i][j]=max(eff,abs(h[x][y]-h[i][j]));
                    pq.push({effort[i][j],{i,j}});
                }
            }
        }

        return -1;
    }
};