#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(vector<int>&arr1,vector<int>&arr2,int k){
    int left = k;
    int l = max(0, k - (int)arr2.size());   
    int h = min(k, (int)arr1.size());


    while(l<=h){
        int mid1 = l + (h-l)/2;
        int mid2 = left-mid1;
        int l1 = INT_MIN,l2=INT_MIN;
        int r1 = INT_MAX,r2=INT_MAX;

        if(mid1<arr1.size()) r1 = arr1[mid1];
        if(mid2<arr2.size()) r2 = arr2[mid2];
        if(mid1-1>=0) l1= arr1[mid1-1];
        if(mid2-1>=0) l2 =arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2) h=mid1-1;
        else l=mid1+1;

    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    vector<int>arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int k;
    cin>>k;

    if(k==1) cout<<min(arr1[0],arr2[0]);
    else{
        if(n<m){
            cout<<solve(arr1,arr2,k);
        }
        else{
            cout<<solve(arr2,arr1,k);
        }
    }
}