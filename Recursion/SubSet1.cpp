#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subSet1(int i,int sum,vector<int>&arr,vector<int>&sums){
    if(i==arr.size()){
        sums.push_back(sum);
        return;
    }

    subSet1(i+1,sum+arr[i],arr,sums);
    subSet1(i+1,sum,arr,sums);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>sums;
    subSet1(0,0,arr,sums);
    sort(sums.begin(),sums.end());

    for(int i=0;i<sums.size();i++){
        cout<<sums[i]<<" ";
    }
}