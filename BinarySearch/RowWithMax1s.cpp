#include<iostream>
#include<vector>
using namespace std;

int lowerBound(int i,vector<vector<int>>&grid){
    vector<int>arr = grid[i];

    int l = 0;
    int h = grid[i].size()-1;
    int ans =-1;

    while(l<=h){
        int m = l + (h-l)/2;

        if(arr[m]==1){
            ans = m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        int idx = lowerBound(i,grid);
        if(idx!=-1){
            mini = min(mini,idx);
        }
    }
    if(mini == INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<mini<<endl;
    }

}