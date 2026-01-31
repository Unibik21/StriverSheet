#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int l=0;
    int h = arr.size()-1;
    int mini = INT_MAX;
    int idx =-1;

    while(l<=h){
        int m = l + (h-l)/2 ;

        if(arr[m]>=arr[l]){
            if(arr[l]<=mini){
                mini = arr[l];
                idx =l;
            }
            l=m+1;
        }
        else{
            if(arr[m]<=mini){
                mini =arr[m];
                idx = m;
            }
            h=m-1;
        }
    }

    cout<<idx;

}