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

    int l = 0;
    int h = n-1;
    int s =-1;
    int e =-1;

    while(l<=h){
        int m = l+ (h-l)/2 ;

        if(arr[m]>=x){
            if(arr[m]==x) s=m;
            h=m-1;
        }
        else{
            l = m+1;
        }
    }
    
    l=0;
    h=n-1;

    while(l<=h){
        int m = l+ (h-l)/2 ;

        if(arr[m]<=x){
            if(arr[m]==x) e=m;
            l = m+1;
        }
        else{
            h=m-1;
        }
    }

    cout<<e-s+1<<endl;
}
