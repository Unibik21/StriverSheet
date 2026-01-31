#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&arr,int m){
    int sum =0;
    int cnt =1;
    for(int i=0;i<arr.size();i++){
        if(sum+arr[i]>m){
            cnt++;
            sum = arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    return cnt;
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

    int l=-1;
    int h=0;
    for(int i=0;i<n;i++){
        if(arr[i]>l){
            l=arr[i];
        }
        h+=arr[i];
    }

    int ans =-1;

    while(l<=h){
        int m = l + (h-l)/2;

        if(solve(arr,m)<=k){
            ans = m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }

    cout<<ans<<endl;
    
}