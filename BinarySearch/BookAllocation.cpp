#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>&arr,int pages){
    int cnt =1;
    int curp =0;
    for(int i=0;i<arr.size();i++){
        if(curp+arr[i]>pages){
            curp=arr[i];
            cnt++;
        }
        else{
            curp+=arr[i];
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int l=-1;
    int h = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i]>l){
            l=arr[i];
        }
        h+=arr[i];
    }
    int ans = -1;

    while(l<=h){
        int mid = l+ (h-l)/2;

        if(solve(arr,mid)<= m){
            h=mid-1;
            ans = mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;


}