#include<iostream>
#include<vector>
using namespace std;

int upperBound(vector<int>&arr,int a){
    int l=0;
    int h = arr.size()-1;

    while(l<=h){
        int m = l+(h-l)/2;

        if(arr[m]<a){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return l;
}

int solve(vector<vector<int>>&mat,int a){
    int cnt = 0;
    for(int i=0;i<mat.size();i++){
        cnt+=upperBound(mat[i],a);
    }
    return cnt;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    int l =INT_MAX;
    int h =INT_MIN;

    for(int i=0;i<mat.size();i++){
        l = min(l,mat[i][0]);
        h = max(h,mat[i][mat[0].size()-1]);
    }

    int half = (mat.size()*mat[0].size())/2;

    int ans =-1;

    while(l<=h){
        int m = l+(h-l)/2;
        int cnt = solve(mat,m);

        if(cnt<=half){
            l=m+1;
        }
        else{
            h=m-1;
            ans =m;
        }


    }


    cout<<ans<<endl;


}