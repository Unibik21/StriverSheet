#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[n];
    }

    unordered_map<int,int>pSum;
    pSum[0]=0;
    int sum = 0;
    int Mlength = 0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(pSum.find(sum) != pSum.end()){
            Mlength = max(Mlength,i-pSum[sum]+1);
        }
        else{
            pSum[sum]=i;
        }
    }

    cout<<Mlength<<endl;
    }
}