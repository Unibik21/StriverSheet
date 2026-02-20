#include<iostream>
#include<vector>
using namespace std;

void shortest_dist(vector<vector<int>>& mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==-1) mat[i][j]=1e9;
            if(i==j) mat[i][j]=0;        
        }
    }
    for(int via=0;via<mat.size();via++){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]= min(mat[i][j],mat[i][via]+mat[via][j]);
            }
        }
    }
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==1e9) mat[i][j]=-1;   
        }
    }

    // for negative cycle

    for(int i=0;i<mat.size();i++){
        if(mat[i][i]<0) cout<<"NEGATIVE CYCLE DETECTED";
    }
}

int main(){

}