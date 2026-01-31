#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p;
    cin>>p;

    int l= 0;
    int h = n/p;
    int ans =-1;

    while(l<=h){
        int m = l + (h-l)/2;
        
        if(pow(m,p)==n){
            ans = m;
            break;
        }
        else if(pow(m,p)<n){
            l = m+1;
        }
        else{
            h=m-1;
        }
    }

    cout<<ans<<endl;
}