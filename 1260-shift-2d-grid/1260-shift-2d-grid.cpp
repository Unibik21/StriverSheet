class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int prev = i*m+j;
                int next = (prev+k)%(n*m);

                int newi = next/m;
                int newj = next%m;

                ans[newi][newj]=grid[i][j];
            }
        }

        return ans;
    }
};