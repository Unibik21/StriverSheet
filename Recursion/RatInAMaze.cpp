#include<iostream>
#include<vector>

using namespace std;

void RatInAMaze(vector<vector<int>>mat,int i,int j,vector<string>&ans,string &a1){
    if(i==mat.size()-1 && j==mat[0].size()-1){
        ans.push_back(a1);
        return;
    }

    mat[i][j]=0;
    
    if(i<mat.size()-1 && mat[i+1][j]!=0){
        a1+='D';
        RatInAMaze(mat,i+1,j,ans,a1);
        a1.pop_back(); 
    }
    if(j<mat[0].size()-1 && mat[i][j+1]!=0){
        a1+='R';
        RatInAMaze(mat,i,j+1,ans,a1);
        a1.pop_back();
    }
    if(i>0 && mat[i-1][j]!=0){
        a1+='U';
        RatInAMaze(mat,i-1,j,ans,a1);
        a1.pop_back();
    }
    if(j>0 && mat[i][j-1]!=0){
        a1+='L';
        RatInAMaze(mat,i,j-1,ans,a1);
        a1.pop_back();
    }
    
    mat[i][j]=1;
}

int main(){
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();

    vector<string>ans ;
    string a1;
    RatInAMaze(maze,0,0,ans,a1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}