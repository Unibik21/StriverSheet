#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    int x;
    cin>>x;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int l=0;
    int h = arr.size();
    bool t = true;

    while(l<=h){
        int m = l + (h-l)/2 ;
        
        if(arr[m]>x){
            h=m;
        }
        else if(arr[m]==x){
            cout<<x<<endl;
            t=false;
            break;
        }
        else if(arr[m]<x){
            l = m+1;
        }
    }

    if(t){
        cout<<h<<endl;
    }
}