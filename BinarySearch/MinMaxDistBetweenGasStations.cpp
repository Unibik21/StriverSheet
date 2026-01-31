#include<iostream>
#include<vector>

using namespace std;
int check(vector<int>&arr,double diff){
    int cnt = 0;
    for(int i=0;i<arr.size()-1;i++){
        double d =arr[i+1]-arr[i];
        cnt+=ceil(d/diff) -1;
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

    double l = 0;
    double h = 0;
    for(int i=0;i<n-1;i++){
        h=max(h,(double)arr[i+1]-arr[i]);
    }

    while(h-l>1e-6){
        double m = l + (h-l)/2;

        if(check(arr,m)<=k){
            h=m;
        }
        else{
            l=m;
        }
    }
    
    cout<<h<<endl;
}