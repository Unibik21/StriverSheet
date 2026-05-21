class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));

        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            mat[u][v]=wt;
            mat[v][u]=wt;
        }

        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }

        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }


        int mini = INT_MAX;
        int m = -1;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(d>=mat[i][j])cnt++;
            }
            if(mini>=cnt){
                mini = cnt;
                m=i;
            }
        }

        return m;
    }
};