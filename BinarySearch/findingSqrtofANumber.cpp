#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    
    int l = 0;
    int h = n/2;
    int ans =-1;

    while(l<=h){
        int m = l+ (h-l)/2;
        
        if(m*m<=n){
            ans = m;
            l=m+1;
        }
        else{
            h=m-1;
        }
    }

    cout<<ans<<endl;

}