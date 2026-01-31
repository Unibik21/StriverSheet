#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solve(vector<int>&arr,int n,int cows){
    int curr=1;
    int lastPos = arr[0];
    for(int i=0;i<arr.size()-1;i++){
       if(arr[i]-lastPos>=n){
        curr++;
        lastPos=arr[i];

        if(curr==cows) return true;
       }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int k; 
    cin>>k;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    int l = 1;
    int h = arr[n-1]-arr[0];
    int ans =-1;

    while(l<=h){
        int m = l + (h-l)/2;

        if(solve(arr,m,k)){
            l=m+1;
            ans = m;
        }
        else{
            h=m-1;
        }
    }

    cout<<ans;
}