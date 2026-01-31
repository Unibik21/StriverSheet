//TC = 2N
//SC = 1


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
    int k;
    cin>>k;

    int l=0;
    int r =0;
    int len = 0;
    int sum =0;
    
    while(r<n){    
        sum+=arr[r];
        if(sum==k){
            len = max(len,r-l+1);
        }
        else if(sum>k){
            sum-=arr[l];
            l++;
        }
        r++;
    }

    cout<<len<<endl;
    
}